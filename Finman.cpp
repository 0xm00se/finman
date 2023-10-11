#include <iostream>
#include <fstream>
using namespace std;

int main(){

	int employeeid, hoursworked, employeecount, menuoption;
	float hourlyrate, grosspay, taxamount, netpay;
	float const TAXRATE = 0.20;
	fstream fout("data.txt", ios::app);
	ifstream fin("data.txt");
	
	while(1){

		cout << "Please Choose from the available options: " << endl;
		cout << " 1. Print Employee Data \n 2. Calculate Employee Data \n 3. Add Employee \n 4. View Employee Data \n 5. View Employee Data with Tax Information (edits the input) \n 6. Exit" << endl;
		cin >> menuoption; // takes in different options this is the main switch control
		cout << "---------------------------" << endl;
		

		switch(menuoption){
			case 1:
				cout << "How many employees would you like to enter? (less than 50) ";
				cin >> employeecount;
				
				while (employeecount > 0) {
				    
				    cout << "Enter the Employee ID: ";
				    cin >> employeeid;
				    cout << "Enter the Number of Hours Worked: ";
				    cin >> hoursworked;
				    cout << "Enter the Hourly Rate: ";
				    cin >> hourlyrate;
				
				    char maritalStatus;
				    cout << "Enter marital status (S=Single, M=Married, H=Head of Household): ";
				    cin >> maritalStatus;
				    maritalStatus = toupper(maritalStatus); 
				
				    grosspay = hoursworked * hourlyrate;
				
				    float taxRate; // main tax calculator
				    if (grosspay > 1000) {
				        taxRate = 0.30;
				    } else if (grosspay > 800 && grosspay <= 1000) {
				        taxRate = 0.20;
				    } else if (grosspay > 500 && grosspay <= 800) {
				        taxRate = 0.10;
				    } else {
				        taxRate = 0;
				    }
				

				    if (maritalStatus == 'S') { // marital tax calculator
				        taxRate += 0.05;
				    } else if (maritalStatus == 'H') {
				        taxRate -= 0.05;
				    }
				
				    taxamount = grosspay * taxRate;
				    netpay = grosspay - taxamount;
				
					//output board
				    cout << "Employee ID: "<<employeeid<<endl;
				    cout << "Hours Worked: "<<hoursworked<<endl;
				    cout << "Hourly Rate: $"<<hourlyrate<<endl;
				    cout << "Grosspay: $"<<grosspay<<endl;
				    cout << "Tax Amount: $"<<taxamount<<endl;
				    cout << "NetPay: $"<<netpay<<endl;
				    cout << "---------------------------" << endl;
				
				    employeecount--;
				}
				
				cout << "---------------------------" << endl;
				break;
			case 2:
				cout << "Enter the Employee ID: ";
				cin >> employeeid;
				cout << "Enter the Number of Hour Worked: ";
				cin >> hoursworked;
				cout << "Enter the Hourly Rate: ";
				cin >> hourlyrate;
				
				grosspay = hoursworked*hourlyrate;
				taxamount=grosspay*TAXRATE;
				netpay=grosspay-taxamount;
				
				cout << "Employee ID: " << employeeid << endl;
	            cout << "Hours Worked: " << hoursworked << endl;
	            cout << "Hourly Rate: $" << hourlyrate << endl;
	            cout << "---------------------------" << endl;
				break;
			case 3:
				cout << "Enter the Employee ID: ";
		        cin >> employeeid;
		        cout << "Enter the Number of Hour Worked: ";
		        cin >> hoursworked;
		        cout << "Enter the Hourly Rate: $";
		        cin >> hourlyrate;
		        
		        if (fout.is_open()) {
		            fout << employeeid << "," << hoursworked << "," << hourlyrate << endl;
		            fout.close();
		        } else {
		            cerr << "Failed to open data.txt for appending." << endl;
		        }
		        
				cout << "---------------------------" << endl;
		        break;
			case 4:
				cout << "How many employees would you like to see? ";
					cin >> employeecount;
					if(employeecount){
						do{						
							if (employeecount > 0){
								fin>>employeeid>>hoursworked>>hourlyrate;
								cout << "Employee ID: " << employeeid << endl;
							    cout << "Hours Worked: " << hoursworked << endl;
							    cout << "Hourly Rate: $" << hourlyrate << endl;
							    cout << "---------------------------" << endl;
							    employeecount--;							    
							}
						}while(employeecount >0);
					}
					
					cout << "Action Complete" << endl;
					cout << "---------------------------" << endl;
					break;
			case 5:
				cout << "How many employees would you like to see? ";
				cin >> employeecount;
				
				char maritalStatus;
				
				if (employeecount) {
				    do {
				        if (employeecount > 0) {
				            fin >> employeeid >> hoursworked >> hourlyrate;
				
				            cout << "Enter marital status (S=Single, M=Married, H=Head of Household): ";
				            cin >> maritalStatus;
				            maritalStatus = toupper(maritalStatus);
				
				            float totalPay = hoursworked * hourlyrate;
				            float taxRate;
				
				            if (totalPay > 1000) {
				                taxRate = 0.30;
				            } else if (totalPay > 800 && totalPay <= 1000) {
				                taxRate = 0.20;
				            } else if (totalPay > 500 && totalPay <= 800) {
				                taxRate = 0.10; 
				            } else {
				                taxRate = 0;
				            }
				
				            
				            if (maritalStatus == 'S') {
				                taxRate += 0.05; 
				            } else if (maritalStatus == 'H') {
				                taxRate -= 0.05; 
				            }
				
				            float taxAmount = totalPay * taxRate;
				            float payAfterTaxes = totalPay - taxAmount;
				
				            cout << "Employee ID: " << employeeid << endl;
				            cout << "Hours Worked: " << hoursworked << endl;
				            cout << "Hourly Rate: $" << hourlyrate << endl;
				            cout << "Total Pay: $" << totalPay << endl;
				            cout << "Tax Amount: $" << taxAmount << endl;
				            cout << "Pay After Taxes: $" << payAfterTaxes << endl;
				            cout << "---------------------------" << endl;
				
				            employeecount--;
				        }
				    } while (employeecount > 0);
				}
				
				cout << "Action Complete" << endl;
				cout << "---------------------------" << endl;
				break;								                                                                                       
			case 6:
				return 0;
		}
	}
	return 0;
} 
