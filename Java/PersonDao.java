package Database;
import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class PersonDao {

    //------------------------------------------add--------------------------------------------------------
    public void addPerson(Person person)throws SQLException{
        //�����õ����ݿ������
        Connection conn=DBUtil.getConnection();
        String sql="" + 
                "insert into BasicInfo"+
                "(id,name,age) "+
                "values(?,?,?)";//������?��ʾ���൱��ռλ��;
        
        //Ԥ����sql���
        PreparedStatement psmt = conn.prepareStatement(sql);
        
        //�ȶ�ӦSQL��䣬��SQL��䴫�ݲ���
        psmt.setInt(1, person.getId());
        psmt.setString(2, person.getName());
        psmt.setInt(3, person.getAge());
        
        //ִ��SQL���
        psmt.execute();
        /**
         * prepareStatement��������ὫSQL�����ص���������conn���ɳ����У����ǲ���ֱ��ִ��
         * ���ǵ�������execute()������ʱ�������ִ�У�
         * 
         * ����SQL�еĲ�����?��ʾ���൱��ռλ����Ȼ���ڶԲ������и�ֵ��
         * ������ִ��ʱ����Щ�����������SQL����У���SQL���ƴ��������ȥִ�С�
         * �����ͻ���ٶ����ݿ�Ĳ���
         */
    }
    //------------------------------------------add--------------------------------------------------------
    //------------------------------------------update--------------------------------------------------------
    
    public void updatePerson(Person person)throws SQLException{
        //�����õ����ݿ������
        Connection conn=DBUtil.getConnection();
        String sql="" + 
                "update BasicInfo set name = ?,age = ? where id = ?";//������?��ʾ���൱��ռλ��
        
        //Ԥ����sql���
        PreparedStatement psmt = conn.prepareStatement(sql);
        
        //�ȶ�ӦSQL��䣬��SQL��䴫�ݲ���
        psmt.setString(1, person.getName());
        psmt.setInt(2, person.getAge());
        psmt.setInt(3, person.getId());
        
        //ִ��SQL���
        psmt.execute();
    }
    //------------------------------------------update--------------------------------------------------------
    //------------------------------------------delete--------------------------------------------------------
    
    public void deletePerson(int id) throws SQLException{
        Connection conn=DBUtil.getConnection();
        String sql="" + 
                "delete from BasicInfo where id = ?";
        PreparedStatement psmt = conn.prepareStatement(sql);
        psmt.setInt(1,id);
        
        //ִ��SQL���
        psmt.execute();
    }
    //------------------------------------------delete--------------------------------------------------------
    //------------------------------------------SearchOne--------------------------------------------------------
    
    public Person SearchOne(int id) throws SQLException{
        Person p = null;
        Connection conn=DBUtil.getConnection();
        String sql="" + 
                "select * from BasicInfo where id = ?";
        PreparedStatement psmt = conn.prepareStatement(sql);
        psmt.setInt(1,id);
        
        //ִ��SQL���
        ResultSet rs = psmt.executeQuery();
        while(rs.next()){
            p = new Person();
            p.setId(rs.getInt("id"));
            p.setName(rs.getString("name"));
            p.setAge(rs.getInt("age"));
        }
        return p;
    }
    //------------------------------------------SearchOne--------------------------------------------------------
    //------------------------------------------Search--------------------------------------------------------
    
    public List<Person> Search() throws SQLException{
        Connection conn = DBUtil.getConnection();
        Statement stmt = conn.createStatement();
        ResultSet rs =  stmt.executeQuery("select id,name,age from BasicInfo");
        List<Person> people = new ArrayList<Person>();
        Person p = null;
        while(rs.next()){//��������������ݣ��ͻ�ѭ����ӡ����
            p = new Person();
            p.setId(rs.getInt("id"));
            p.setName(rs.getString("name"));
            p.setAge(rs.getInt("age"));
            people.add(p);
        }
        return people;
        
    }
    //------------------------------------------Search--------------------------------------------------------
    
}