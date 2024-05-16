#include<iostream>
#include<stdlib.h>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

namespace View
{

	class UI
	{
		public:
			void prompt(string s)
			{
				cout<<s<<"\n";	
			}

			void prompt(int i)
			{
				cout<<i<<"\n";
			}

			vector<float> getInput()
			{
				float num1, num2;
				cin>>num1>>num2;
				return {num1,num2};
			}
			char getInput_char()
			{
				char opcode;
				cin>>opcode;
				return opcode;
			}	
	};
};

namespace Model
{

	class storage
	{
		private:
			vector<float>storage_vec; char opcode;

		public:
			void store_vec(vector<float>& nums)
			{
				for(int i=0;i<nums.size();i++)
				{
					storage_vec.push_back(nums[i]);
				}			
			}	

			void store(char op)
			{
				opcode = op;
			}

			char retrieve_char()
			{
				return opcode;
			}

			vector<float> retrieve()
			{
				return storage_vec;
			}
	};
};

/* Controller interacts with View and Model. View and Model do not interact with each other*/
namespace Controller
{

	class Logic
	{
		View::UI* u;
		Model::storage *s;

		public:
		Logic(View::UI *_u, Model::storage *_s)
		{
			u=_u;
			s=_s;

			dologic();

		}

		void dologic()
		{
			//ask user for a number 
			u->prompt("Enter the number");
			vector<float>ret = u->getInput();
		
			u->prompt("Enter the operation you want to perform: +, -, *, /");
                        char c = u->getInput_char();

			//store the number storage object.

			s->store_vec(ret);

			s->store(c);
	
			//retrieve that number from storage object.
	
			vector<float>ret1 = s->retrieve();
		
			char op = s->retrieve_char();
		
		

			//display that to the user using UI object.
			u->prompt("Your answer is :");
			switch(op) {
	
  	 		case '+':
      				cout << ret1[0] << " + " << ret1[1] << " = " << ret1[0] + ret1[1];
		        	break;

   		 	case '-':
      				cout << ret1[0] << " - " << ret1[1] << " = " << ret1[0] - ret1[1];
    				break;

		 	case '*':
		        	cout << ret1[0] << " * " << ret1[1] << " = " << ret1[0] * ret1[1];
		        	break;

		 	case '/':
				cout << ret1[0] << " / " << ret1[1] << " = " << ret1[0] / ret1[1];     			
				break;

		 	default:
 		   		 // If the operator is other than +, -, * or /, error message is shown
      				cout << "Error! operator is not correct";
      				break;
  			}
	
		}
	};
};


	int main()
	{
		View::UI u;
		Model::storage s;
		
		Controller::Logic l(&u, &s); 

		return 0;
	}
