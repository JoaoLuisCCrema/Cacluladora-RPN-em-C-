//Joao Luis Chiarelotto Crema
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <stack>
using namespace std;

int main()
{
	stack<char> operadores;	
	stack<char> saida;		
	stack<char> temp;		
	stack<char> resposta;	
	string comando;

	cout << "Digite a operacao => ";
	cin >> comando;
	
	// Algoritmo Shunting Yard: https://en.wikipedia.org/wiki/Shunting_yard_algorithm
	for(int i=0; i<comando.size(); i++)
	{
		switch(comando[i])
		{
		case '*': case '+': case '-': case '/': case'(': 
			operadores.push(comando[i]);
			break;

		case ')':
			while(operadores.top() != '(')
			{
				saida.push(operadores.top());
				operadores.pop();
			}
			operadores.pop();
			break;

		default:
			saida.push(comando[i]);
			break;
		}
	}
	while(!operadores.empty())
	{
		saida.push(operadores.top());
		operadores.pop();
	}

	// Inverte a saída
	while(!saida.empty())
	{
		temp.push(saida.top());
		saida.pop();
	}
	while(!temp.empty())
	{
		if(temp.top() == '+')
		{
			stringstream res;
			int a = resposta.top() - '0'; // gambiarra
			resposta.pop();
			int b = resposta.top() - '0';
			resposta.pop();
			res << b+a;
			cout << "B+A=" << b+a << endl;
			resposta.push(b+a);
		} 
		else if(temp.top() == '-')
		{
			stringstream res;
			int a = resposta.top() - '0';
			resposta.pop();
			int b = resposta.top() - '0';
			resposta.pop();
			res << b-a;
			cout << "B-A=" << b-a << endl;
			resposta.push(b-a);
		} 
		else if(temp.top() == '*')
		{
			stringstream res;
			int a = resposta.top() - '0';
			resposta.pop();
			int b = resposta.top() - '0';
			resposta.pop();
			res << b*a;
			cout << "B*A=" << b*a << endl;
			resposta.push(b*a);
		} 
		
		else if(temp.top() == '/')
		{
			stringstream res;
			int a = resposta.top() - '0';
			resposta.pop();
			int b = resposta.top() - '0';
			resposta.pop();
			res << b/a;
			cout << "B/A=" << b/a << endl;
			resposta.push(b/a);
		} 
		
		else {
			resposta.push(temp.top());
		}
		
		temp.pop();
	}
	system("pause");
	return 0;
}
