import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.Socket;
import java.net.SocketException;
import java.net.UnknownHostException;
import java.util.StringTokenizer;

import sun.misc.BASE64Encoder;

class MailMessage {

    private String from;
    private String to;
    private String datafrom;
    private String datato;
    private String subject;
    private String content;
    private String date;
    private String user;
    private String password;

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public String getUser() {
        return user;
    }

    public void setUser(String user) {
        this.user = user;
    }

    public String getContent() {
        return content;
    }

    public void setContent(String content) {
        this.content = content;
    }

    public String getDatafrom() {
        return datafrom;
    }

    public void setDatafrom(String datafrom) {
        this.datafrom = datafrom;
    }

    public String getDatato() {
        return datato;
    }

    public void setDatato(String datato) {
        this.datato = datato;
    }

    public String getDate() {
        return date;
    }

    public void setDate(String date) {
        this.date = date;
    }

    public String getFrom() {
        return from;
    }

    public void setFrom(String from) {
        this.from = from;
    }

    public String getSubject() {
        return subject;
    }

    public void setSubject(String subject) {
        this.subject = subject;
    }

    public String getTo() {
        return to;
    }

    public void setTo(String to) {
        this.to = to;
    }

}

public class Main {

    private boolean debug=true;
    BASE64Encoder encode=new BASE64Encoder();//���ڼ��ܺ����û���������
    public static void main(String[] args) throws UnknownHostException, IOException {
        // TODO Auto-generated method stub
        MailMessage message=new MailMessage();
        message.setFrom("liuq901@126.com");//������
        message.setTo("liuq901@163.com");//�ռ���
        String server="smtp.126.com";//�ʼ�������
        message.setSubject("test");//�ʼ�����
        message.setContent("test");//�ʼ�����
        message.setDatafrom("Matt");//�����ˣ����ʼ��ķ�������Ŀ����ʾ
        message.setDatato("Dong");//�ռ��ˣ����ʼ����ռ�����Ŀ����ʾ
        message.setUser("liuq901");//��½������û���
        message.setPassword("7894561230");//��½���������

        Main smtp=new Main(server,25);
        boolean flag;
        flag=smtp.sendMail(message,server);
        if(flag){
            System.out.println("�ʼ����ͳɹ���");
        }
        else{
            System.out.println("�ʼ�����ʧ�ܣ�");
        }

    }
    private Socket socket;
    public Main(String server,int port) throws UnknownHostException, IOException{
        try{
            socket=new Socket(server,25);
        }catch(SocketException e){
            System.out.println(e.getMessage());
        }catch(Exception e){
            e.printStackTrace();
        }finally{
            System.out.println("�Ѿ���������!");
        }

    }
    //ע�ᵽ�ʼ�������
    public void helo(String server,BufferedReader in,BufferedWriter out) throws IOException{
        int result;
        result=getResult(in);
        //�������ʼ������,����������220Ӧ��
        if(result!=220){
            throw new IOException("���ӷ�����ʧ��");
        }
        result=sendServer("HELO "+server,in,out);
        //HELO����ɹ��󷵻�250
        if(result!=250)
        {
            throw new IOException("ע���ʼ�������ʧ�ܣ�");
        }
    }

    private int sendServer(String str,BufferedReader in,BufferedWriter out) throws IOException{
        out.write(str);
        out.newLine();
        out.flush();
        if(debug)
        {
            System.out.println("�ѷ�������:"+str);
        }
        return getResult(in);
    }
    public int getResult(BufferedReader in){
        String line="";
        try{
            line=in.readLine();
            if(debug){
                System.out.println("����������״̬:"+line);
            }
        }catch(Exception e){
            e.printStackTrace();
        }
        //�ӷ�����������Ϣ�ж���״̬��,����ת������������
        StringTokenizer st=new StringTokenizer(line," ");
        return Integer.parseInt(st.nextToken());
    }

    public void authLogin(MailMessage message,BufferedReader in,BufferedWriter out) throws IOException{
        int result;
        result=sendServer("AUTH LOGIN",in,out);
        if(result!=334){
            throw new IOException("�û���֤ʧ�ܣ�");
        }

        result=sendServer(encode.encode(message.getUser().getBytes()),in,out);
        if(result!=334){
            throw new IOException("�û�������"); 
        }
        result=sendServer(encode.encode(message.getPassword().getBytes()),in,out);

        if(result!=235){
            throw new IOException("��֤ʧ�ܣ�"); 
        }
    }
    //��ʼ������Ϣ���ʼ�Դ��ַ
    public void mailfrom(String source,BufferedReader in,BufferedWriter out) throws IOException{
        int result;
        result=sendServer("MAIL FROM:<"+source+">",in,out);
        if(result!=250){
            throw new IOException("ָ��Դ��ַ����");
        }
    }
    // �����ʼ��ռ���
    public void rcpt(String touchman,BufferedReader in,BufferedWriter out) throws IOException{
        int result;
        result=sendServer("RCPT TO:<"+touchman+">",in,out);
        if(result!=250){
            throw new IOException("ָ��Ŀ�ĵ�ַ����");
        }
    }

    //�ʼ���
    public void data(String from,String to,String subject,String content,BufferedReader in,BufferedWriter out) throws IOException{
        int result;
        result=sendServer("DATA",in,out);
        //����DATA�س���,���յ�354Ӧ���,���������ʼ�����
        if(result!=354){
            throw new IOException("���ܷ�������");
        }
        out.write("From: "+from);
        out.newLine();
        out.write("To: "+to);
        out.newLine();
        out.write("Subject: "+subject);
        out.newLine();
        out.newLine();
        out.write(content);
        out.newLine();
        //��żӻس������ʼ���������
        result=sendServer(".",in,out);
        System.out.println(result);
        if(result!=250)
        {
            throw new IOException("�������ݴ���");
        }
    }

    //�˳�
    public void quit(BufferedReader in,BufferedWriter out) throws IOException{
        int result;
        result=sendServer("QUIT",in,out);
        if(result!=221){
            throw new IOException("δ����ȷ�˳�");
        }
    }

    //�����ʼ�������
    public boolean sendMail(MailMessage message,String server){
        try{
            BufferedReader in=new BufferedReader(new InputStreamReader(socket.getInputStream()));
            BufferedWriter out=new BufferedWriter(new OutputStreamWriter(socket.getOutputStream()));
            helo(server,in,out);//HELO����
            authLogin(message,in,out);//AUTH LOGIN����
            mailfrom(message.getFrom(),in,out);//MAIL FROM
            rcpt(message.getTo(),in,out);//RCPT
            data(message.getDatafrom(),message.getDatato(),message.getSubject(),message.getContent(),in,out);//DATA
            quit(in,out);//QUIT
        }catch(Exception e){
            e.printStackTrace();
            return false;

        }
        return true;
    }

}

