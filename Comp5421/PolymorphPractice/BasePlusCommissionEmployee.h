//
// Created by Vithu Maheswaran on 2022-07-13.
//

#ifndef POLYMORPHPRACTICE_BASEPLUSCOMMISSIONEMPLOYEE_H
#define POLYMORPHPRACTICE_BASEPLUSCOMMISSIONEMPLOYEE_H

#include "CommissionEmployee.h"


class BasePlusCommissionEmployee: public CommissionEmployee {

    double baseSalary;

public:
    double getSalary();
    void setSalary();
};


#endif //POLYMORPHPRACTICE_BASEPLUSCOMMISSIONEMPLOYEE_H
