#include "mail.h"

Mail::Mail(string send, string rec, string zcode):
			sender(send),receiver(rec), zipCode(zcode)
{ }

Mail::~Mail()
{ }

string Mail::getZipCode() const {
	return zipCode;
}


RegularMail::RegularMail(string send, string rec, string zcode, unsigned int w):
			Mail(send, rec, zcode), weight(w)
{ }


GreenMail::GreenMail(string send, string rec, string zcode, string t):
			Mail(send, rec, zcode), type(t)
{ }

unsigned int Mail::getPrice() const {  // if a new type of mail is created this method will be used for it's pricing (unless something like NewTypeMail::getPrice() is implemented)
	return 0;
}

unsigned int RegularMail::getPrice() const {
    if (weight <= 20) return 50;
    if (weight <= 100) return 75;
    if (weight <= 500) return 140;
    else return 325;
}

unsigned int GreenMail::getPrice() const {
    if (type == "envelope") return 80;
    if (type == "bag") return 200;
    if (type == "box") return 240;
    // for exercise purposes we know that there are only these 3 types (an enum could be used in the class definition too to avoid problems later)
    else return 0;
}