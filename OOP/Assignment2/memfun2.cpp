#include <iostream>
#include <iomanip>
#include "header2.h"
using namespace std ;
/// Function declaration for the payroll methods
/// This function is used to get the Net Pay figure.
float payroll::get_net(float taxable_pay)
{
    dm_taxable_pay = taxable_pay;
    dm_net = (dm_taxable_pay - (dm_paye + dm_prsi + dm_usc));
    return dm_net;
}
/// This function is used to get total PRSI figure.
float payroll::get_prsi(float taxable_pay)
{
    dm_taxable_pay = taxable_pay;
    dm_prsi = dm_taxable_pay * 0.04;
    return dm_prsi;
}
/// This function is used to get total PAYE figure.
float payroll::get_paye(float taxable_pay, float E_SRCOP, float tax_credits)
{
    dm_SRCOP = E_SRCOP;
    dm_tax_credit = tax_credits;
    dm_taxable_pay = taxable_pay;
    if (dm_taxable_pay > dm_SRCOP)
    {
        dm_paye = ((dm_taxable_pay - dm_SRCOP) * 0.4) + 135.77;
    }
    else
    {
        dm_paye = dm_taxable_pay * .2;
    }
    dm_paye = dm_paye - dm_tax_credit;
    return dm_paye;
}
/// This function is used to get total USC figure.
float payroll::get_usc(float taxable_pay)
{
    dm_taxable_pay = taxable_pay;
    if (dm_taxable_pay <= 231)
    {
        dm_usc = dm_taxable_pay * 0.005;
    }
    else if (dm_taxable_pay > 231 && dm_taxable_pay <= 382)
    {
        dm_usc = ((dm_taxable_pay - 231) * .02) + (1.155);
    }
    else if (dm_taxable_pay > 382 && dm_taxable_pay <= 1347)
    {
        dm_usc = ((dm_taxable_pay - 382) * .045) + (1.155 + 3.02);
    }
    else
    {
        dm_usc = ((dm_taxable_pay - 1337) * .08) + (1.155 + 3.02 + 43.425);
    }
    return dm_usc;
}
float taxable_pay[4] = {778.85, 1447, 1547, 1600};
int employee_number[4] = {101, 102, 103, 104};
float SCROP[4] = {678.85, 678.85, 678.85, 678.85};
float Wtax_credit[4] = {31.73, 50.67, 59.8, 65.80};
int union_subs[4] = {0, 25, 25, 0};
int VHI[4] = {0, 23, 80, 10};
float PAYE[4];
float prsi[4];
float USC[4];
float net_pay[4];
