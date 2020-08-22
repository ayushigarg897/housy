
#include <iostream>
#include<fstream>
#include<vector>
#include<math.h>

using namespace std;

double activation(double value);

double theta0=0.5,theta1=0.5,ele,sum,sum2,error_sum,alpha=0.001,input_sum=0,output_sum=0,hypothesis_sum=0;
int i,epoch=100;
vector<double> x;
vector<double> y;
vector<double> hypothesis_values;

int main(){
  ifstream infile;
  double input,output;
  infile.open("data.txt");
  if(!infile){
    cerr<<"Unable to find the file";
    exit(1);
  }
  string line;
  while(getline(infile,line)){
    string str="";
    i=0;
    while(line[i]!=','){
      str += line[i];
      i++;
    }
    input=atof(str.c_str());
    x.push_back(input);
    input_sum += input;

    str="";
    i++;
    while(line[i]!=line.length()){
      str += line[i];
      i++;
    }
    output=atof(str.c_str());
    y.push_back(output);
    output_sum += output;
    }

    int size_of_dataset = x.size();


    while(epoch--){
      //activation function

      hypothesis_values.clear();
      double predict_value;

      for(i=0;i<size_of_dataset;i++){
        predict_value = theta0 + (theta1 * x[i]);
        hypothesis_values.push_back(predict_value);
        hypothesis_sum += predict_value;
      }

      error_sum = 0;
      double error=0;

      for(i = 0; i < size_of_dataset; i++){
        error_sum += pow((hypothesis_values[i] - y[i]), 2);
      }
 
      error = error_sum / (size_of_dataset );

      cout<<error<<endl;

     /* double update_weight_sum = 0;

      for(i = 0; i < size_of_dataset; i++){
        update_weight_sum += (hypothesis_values[i] - y[i]) * x[i];
      }

      theta1 = theta1 - (2 * alpha * (update_weight_sum / size_of_dataset));

      double update_bias_sum = 0;

      for(i=0; i < size_of_dataset; i++){
        update_bias_sum += hypothesis_values[i] - y[i];
      }

      theta0 = theta0 - (2 * alpha * (update_bias_sum / size_of_dataset));*/

      theta0 = theta0 - ((alpha*(hypothesis_sum - output_sum)) / size_of_dataset);

      theta1 = theta1 - ((alpha * (hypothesis_sum - output_sum) * input_sum) / size_of_dataset);

       cout<<theta0<<" | "<<theta1<<endl;
    }
  return 0;
