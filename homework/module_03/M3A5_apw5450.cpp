//Author:	    Austin Whaley, APW5450, 2019-01-27
//Class:      CMPSC 121
//Activity:   05
//File:       cmpsc121\homework\module_03/M3A5_apw5450.cpp
//Purpose:    Stock Transaction Program

/********************************************************************\
* Academic Integrity Affidavit:                                      *
* I certify that, this program code is my work.  Others may have     *
* assisted me with planning and concepts, but the code was written,  *
* solely, by me.                                                     *
* I understand that submitting code which is totally or partially    *
* the product of other individuals is a violation of the Academic    *
* Integrity Policy and accepted ethical precepts. Falsified          *
* execution results are also results of improper activities. Such    *
* violations may result in zero credit for the assignment, reduced   *
* credit for the assignment, or course failure.                      *
\********************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

int main(){

  // num_s_purch = number of shares purchased
  // p_price = purchase price
  // c_rt = commision rate
  // s_price = sale price

  unsigned long int num_s_purch;
  double p_price, c_rt, s_price;
  double cost_of_stock_before_commission, commission_on_purchase, total_cost_of_purchase;
  double sale_revenue_before_commission, commission_on_sale, total_cost_of_sale;

  cout << "Enter number of shares purchased, purchase price of stock, commission rate, and saleprice\n";

  // 1000 45.76 .02 57.23 // Test Input // Success
  // 1000 40.01 .03 50.01 // Exe Input // Success
  cin >> num_s_purch >> p_price >> c_rt >> s_price;

  // Set precision of floating point outputs and display in fixed notation
  cout << setprecision(2) << fixed;

  // Print Header
  cout << "********************TRANSACTION DETAILS*********************" << endl;

  // FOR ALL BELOW
  // Evaluate variable and display on far right with 8 character width

  // cost_of_stock_before_commission
  cost_of_stock_before_commission = (num_s_purch * p_price);
  cout << "Cost of stock before commission " << "\t$" << right << setw(8)\
       << cost_of_stock_before_commission << endl;

  // commission_on_purchase
  commission_on_purchase = cost_of_stock_before_commission*c_rt;
  cout << "Commission on purchase "  << "\t\t\t$" << right << setw(8)
       << commission_on_purchase << endl;

  // total_cost_of_purchase
  total_cost_of_purchase = cost_of_stock_before_commission + commission_on_purchase;
  cout << "Total cost of purchase"  << "\t\t\t$" << right << setw(8)\
       << total_cost_of_purchase << endl;

  cout << endl;

  // sale_revenue_before_commission
  sale_revenue_before_commission = (num_s_purch * s_price);
  cout << "Sale revenue before commission" << "\t\t$" << right << setw(8)\
       << sale_revenue_before_commission << endl;

  // commission_on_sale
  commission_on_sale = sale_revenue_before_commission*c_rt;
  cout << "Commission on sale" << "\t\t\t$" << right << setw(8)\
       << commission_on_sale << endl;

  // total_cost_of_sale
  total_cost_of_sale =  sale_revenue_before_commission - commission_on_sale;
  cout << "Total cost of sale" << "\t\t\t$" << right << setw(8)\
       << sale_revenue_before_commission - commission_on_sale << endl;

  cout << endl;

  // profit
  cout << "Profit of loss on sale" << "\t\t\t$" << right << setw(8)\
       << total_cost_of_sale - total_cost_of_purchase << endl;

  return 0;
}

/*

Enter number of shares purchased, purchase price of stock, commission rate, and saleprice
1000 40.01 .03 50.01
********************TRANSACTION DETAILS*********************
Cost of stock before commission         $40010.00
Commission on purchase 			            $ 1200.30
Total cost of purchase			            $41210.30

Sale revenue before commission		      $50010.00
Commission on sale			                $ 1500.30
Total cost of sale			                $48509.70

Profit of loss on sale			            $ 7299.40

*/
