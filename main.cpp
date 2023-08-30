#include<bits/stdc++.h>
using namespace std;
double CI(double P, double R, int T) {
     double A = P * (pow((1 + R / 100), T));
     return A;
}

double Cinflation(double amt, double R, int T) {
     double A = amt * (pow((1 - R / 100), T));
     return A;
}
using namespace std;
const int max_years = 100; // Maximum number of years in the dataset

// Structure to hold data for each year
struct YearData {
    string empty; // Empty space column
    int year;
    double interest;
    double inflation;
    string government;
    string continent;
};

int main() {
    string filename = "india_data.csv"; // Replace with your CSV file path

    YearData data[max_years];
    int num_years = 0; // Actual number of years in the dataset

    // Read the CSV data
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Could not open file: " << filename << endl;
        return 1;
    }

    string line;
    while (getline(file, line) && num_years < max_years) {
        istringstream line_stream(line);
        YearData year_data;
        char delimiter = ',';

        getline(line_stream, year_data.empty, delimiter); // Read and ignore the empty space column
        line_stream >> year_data.year >> delimiter >> year_data.interest >> delimiter >> year_data.inflation >> delimiter;
        getline(line_stream, year_data.government, delimiter);
        getline(line_stream, year_data.continent, delimiter);

        data[num_years] = year_data;
        ++num_years;
    }

    // Print the data without headings
    for (int i = 0; i < num_years; ++i) {
        cout << data[i].year << ", " << data[i].interest << ", " << data[i].inflation << ", "
                  << data[i].government << ", " << data[i].continent << endl;
    }
   


   int P, year;
   cout<<"enter amount invest";
   cin>>P;
    cout<<"enter year";
     cin>>year;
   double R=0;
   int T=2023-year;
   int t=0;
     for(int i=0;i<num_years;i++)
      {
        if(data[i].year == year)
        {
          R=data[i].interest;
          t++;
          break;
        }
        
      }
      --num_years;
      double i_amt=0;
      double amount_received= CI(P,R,T);
      i_amt=amount_received;
      for(int i=num_years;i>=0;i--)
        {
            if(data[i].year>=year)
            {
               i_amt=Cinflation(i_amt,data[i].inflation,1);
            }
            else
            {
                break;
            }
        }
    i_amt=Cinflation(amount_received,data[num_years].inflation,1);
      cout<<"amount received actual "<<round(amount_received * 100)/100 <<"  val of money "<<round(i_amt*100)/100;

    return 0;
}