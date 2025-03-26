#include <iostream>
#include <mysql/jdbc.h>

using namespace std;
using namespace sql;

#define SERVER_IP "localhost:3306"
#define USERNAME "root"
#define PASSWORD "12345"
#define DATABASE "testDB"

class MySQLConnector{
private:
	string server;
	string username;
	string password;
	string database;
	
	unique_ptr<Connection> conn;

public:
	MySQLConnector(const string& server, const string& username, const string& password, const string database)
	: server(server), username(username), password(password), database(database) {
		try
		{
			mysql::MySQL_Driver* driver = mysql::get_mysql_driver_instance();
			conn = unique_ptr<Connection>(driver->connect(server, username, password));
			conn->setSchema(this->database);
			cout << "MySQL Connection success!" << endl;
		}
		catch (SQLException& e) {
			cerr << "DB connection failed..." << e.what() << endl;
		}
	}
	~MySQLConnector() {
		cout << "MySQL disconnect" << endl;
	}

};

int main() {

	MySQLConnector db(SERVER_IP, USERNAME, PASSWORD, DATABASE);

	return 0;
}