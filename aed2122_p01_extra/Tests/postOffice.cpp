#include "postOffice.h"
#include <string>

PostOffice::PostOffice(string firstZCode, string lastZCode):
								firstZipCode(firstZCode), lastZipCode(lastZCode)
{}
PostOffice::PostOffice() {}

void PostOffice::addMailToSend(Mail *m) {
	mailToSend.push_back(m);
}

void PostOffice::addMailToDeliver(Mail *m) {
	mailToDeliver.push_back(m);
}

void PostOffice::addPostman(const Postman &p){
	postmen.push_back(p);
}

vector<Mail *> PostOffice::getMailToSend() const {
	return mailToSend;
}

vector<Mail *> PostOffice::getMailToDeliver() const {
	return mailToDeliver;
}

vector<Postman> PostOffice::getPostman() const {
	return postmen;
}


vector<Mail *> PostOffice::removePostman(string name) {
    for (int i = 0; i < postmen.size(); i++){
        if (postmen.at(i).getName() == name){
            vector<Mail *> res = postmen.at(i).getMail();
            postmen.erase(postmen.begin() +i);
            return res;
        }
    }
	vector<Mail *> res;
	return res;
}

vector<Mail *> PostOffice::endOfDay(unsigned int &balance) {
    vector <Mail *> res;
    balance = 0;
	for (Mail *  m : mailToSend){
        balance += m->getPrice();
        if (m->getZipCode() > firstZipCode && m->getZipCode() < lastZipCode)
            addMailToDeliver(m);
        else
            res.push_back(m);
    }
    mailToSend.clear();
    return res;
}


Postman PostOffice::addMailToPostman(Mail *m, string name) {
    for (int i = 0; i < postmen.size(); i++){
        if (postmen.at(i).getName() == name){
            Postman p1 = postmen.at(i);
            p1.addMail(m);
            return p1;
        }
    }
    throw(NoPostmanException(name));

}

