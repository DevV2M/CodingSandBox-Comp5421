//
// Created by Vithu Maheswaran on 2022-07-13.
//

#ifndef POLYMORPHPRACTICE_COMMISSIONEMPLOYEE_H
#define POLYMORPHPRACTICE_COMMISSIONEMPLOYEE_H

#include <string>
using std::string;

class CommissionEmployee {

private:
    string firstname;
    string lastname;
    string socialSecurityNumber;
    double grossSales;
    double commissionRate;

public:
    CommissionEmployee();
    string getFirstname();
    string lastFirstname();
    string getSSN();
    double getGrossSales();
    double getCommissionRate();
    string setSSN();
    double setGrossSales();
    double setCommissionRate();
    double earnings();
    string to_string();
};


#endif //POLYMORPHPRACTICE_COMMISSIONEMPLOYEE_H
