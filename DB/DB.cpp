#include <iostream>
#include <mysql/jdbc.h>

using namespace std;
using namespace sql;

int main() {

	try {
		mysql::MySQL_Driver* driver;
		Connection* con;

		driver = mysql::get_driver_instance();

		con = driver->connect("tcp://localhost:3306", "root", "12345");
		con->setSchema("madang");

		cout << "DB connection successful!!" << endl;
	}
	catch (SQLException &e) {
		cerr << "DB connection failed..." << e.what() << endl;
	}
		
	return 0;
}