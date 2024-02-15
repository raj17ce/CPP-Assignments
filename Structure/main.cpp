#include <iostream>

struct Name {
	const char* firstName;
	const char* middleName;
	const char* lastName;
};

struct Address {
	const char* street;
	const char* landMark;
	const char* dist;
	const char* state;
	const char* country;
	int pincode;
	int houseNumber;
};

struct BirthDate {
	int day;
	int month;
	int year;
};

struct Aadhaar {
	Address addr;
	Name name;
	BirthDate birthDate;
	long long mobileNumber;
	long long aadhaarNumber;

	Aadhaar() {

		mobileNumber = 1111222233;
		aadhaarNumber = 111122223333;

		birthDate.day = 01;
		birthDate.month = 01;
		birthDate.year = 1970;
	}
};

void addName(Aadhaar& a, const char* firstName, const char* lastName, const char* middleName = "") {
	a.name.firstName = firstName;
	a.name.middleName = middleName;
	a.name.lastName = lastName;
}

void addMobileNumber(Aadhaar& a, long long mobileNumber) {
	a.mobileNumber = mobileNumber;
}

void addAadhaarNumber(Aadhaar& a, long long aadhaarNumber) {
	a.aadhaarNumber = aadhaarNumber;
}

void addBirthDate(Aadhaar& a, int day, int month, int year) {
	a.birthDate.day = day;
	a.birthDate.month = month;
	a.birthDate.year = year;
}

void addAddress(Aadhaar& a, int houseNumber, const char* street, const char* landMark, const char* dist, const char* state, const char* country, int pincode) {
	a.addr.houseNumber = houseNumber;
	a.addr.street = street;
	a.addr.landMark = landMark;
	a.addr.dist = dist;
	a.addr.state = state;
	a.addr.country = country;
	a.addr.pincode = pincode;
}

void display(const Aadhaar& a) {
	std::cout << "Aadhaar Information is below: " << "\n";
	std::cout << "Name : " << a.name.firstName << " " << a.name.middleName << " " << a.name.lastName << "\n";
	std::cout << "Aadhaar Number : " << a.aadhaarNumber << "\n";
	std::cout << "Mobile Number : " << a.mobileNumber << "\n";
	std::cout << "Birth Date : " << a.birthDate.day << "-" << a.birthDate.month << "-" << a.birthDate.year << "\n";
	std::cout << "Address : " << a.addr.houseNumber << ", " << a.addr.street << ", " << a.addr.landMark << ", " << a.addr.dist << ", " << a.addr.state << ", " << a.addr.pincode << ", " << a.addr.country << "\n\n";
}


int main() {
	Aadhaar a; //uninitialized : default constructor called

	addName(a, "Raj", "Patel", "Bharatbhai");
	addMobileNumber(a, 7777666699);
	addAadhaarNumber(a, 777788889999);
	addBirthDate(a, 17, 4, 2003);;
	addAddress(a, 91, "XYZ Apartments", "Opposite ABCD Ground", "Valsad", "Gujarat", "India", 400037);

	display(a);
}