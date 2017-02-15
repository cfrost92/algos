#include <iostream>
#include <cstdlib>//for "exit()" on some systems
#include <vector>
#include <string>

using namespace std;

/**
\fn linearSearch
\brief Search data for the first occurrence of key
\param [in] key The value being searched for
\param [in] data The data set that will be searched
\returns location of key if found or -1 if not found
*/
int linearSearch(auto data, auto key)//prototype
{
		for(int i=0; i<data.size(); i++)
		{
			if(data[i]==key)
				return i;
		}//end for loop

	return -1; //if key is not found

	}//end of linear search algorithm/function


void insertionSort(auto& Data)
{
	for(int i=0; i<Data.size()-1; i++)
	{
		int j=i+1;
		while(j>0 and Data[j-1]>Data[j])
		{
			swap(Data[j], Data[j-1]);
			j=j-1;
		}//end while
	}//end for
}//end sort


int main()
{
  vector<string> inputs;
  string search_key, input;
  int result;

   cout<<"Welcome to \"search it\". We first need some input data."<<endl;
   cout<<"We'll assume the inputs do not have any spaces."<<endl<<endl;
   cout<<"To end input type the #-character (followed by Enter)"<<endl<<endl;

   cin>>input;
 
    while(input != "#")//read an unknown number of inputs from keyboard
    {
       inputs.push_back(input);
       cin>>input;
    }

   cout<<endl<<"["<<inputs.size()<<" values read from input source]"<<endl<<endl;

  if(inputs.size() == 0)//no input
  {
      cout<<endl<<"No input received, quiting..."<<endl<<endl;
       exit(1);//nothing to do but quit program
  }
  
  
insertionSort(inputs);

for(int i=0; i<inputs.size(); i++)
{
	cout<< inputs[i] << endl;
}
	
 
	cout<<endl<<"To end input type the #-character (followed by Enter)"<<endl<<endl;
	cout<<"Enter a value to search for: ";


   cin>>search_key;
 
	
 
    while(search_key != "#")//perform searches until sentinel entered
    {
        result = linearSearch(inputs,search_key);

        cout<<"  '"<<search_key<<"' was ";

        if (result == -1)
          cout<<"not found";
        else
          cout<<"found at index "<<result;


        cout<<endl<<endl<<"Enter a value to search for: ";
        cin>>search_key; 
    }

   cout<<endl<<"Program \"search it\" is now finished."<<endl<<endl;

    return 0;
}
