//#include<iostream>
//#include<fstream>
//#include<string>
//#include<vector>
//using namespace std;
//
//vector<string> seperateString(vector<char>, string);
//vector<char> getPremisis(string);
//int searchResult(vector<string>, string);
//int searchResult(vector<char>, char);
//int searchResult(vector<int>, int);
//vector<vector<bool>> setTruthTable(vector<char>, vector<string>);
//void displayChar(vector<char>);
//void displayString(vector<string>);
//void displayBool(vector<string>, vector<vector<bool>>);
//void display(vector<vector<bool>>);
//bool checkTruthTableEquivalance(vector<char>, vector<vector<bool>>, vector<vector<bool>>);
//vector<bool> getLastColumn(vector<string>, vector<vector<bool>>);
//bool checkValidation(vector<vector<bool>>);
//
//fstream write("Q1-B.csv", ios::out);
//
//int main()
//{
//	vector<vector<bool>> main;
//	vector<string> allPremisis;
//	string rawString = "", prem = "";
//	int i = 1;
//	while (true)
//	{
//		cout << "\t\t*** ARGUMENT VALIDATOR ***\n";
//		cout << "\n(1) 'V' for OR\n(2) '^' for AND\n(3) '~' for NOT\n(4) '->' for IMPLICATION\n(5) '<->' for DOUBLE IMPLICATION'\n\n*** BRACKETS ARE ABSOLUTELLY NECCESSARY ***\n";
//		cout << "\nEnter Premisis No. " << i << "\n(*PRESS 0 to enter the CONCLUSION*)\nInput: ";
//		cin >> rawString;
//
//		if (rawString == "0")
//		{
//			break;
//		}
//
//		prem += rawString;
//		allPremisis.push_back(rawString);
//		i++;
//	}
//
//	cout << "\nEnter Conclusion: ";
//	cin >> rawString;
//
//	prem += rawString;
//	allPremisis.push_back(rawString);
//
//	vector<char> mainPremisis = getPremisis(prem);
//
//	for (int i = 0; i < allPremisis.size(); i++)
//	{
//		vector<string> tempPremisis = seperateString(mainPremisis, allPremisis[i]);
//		vector<vector<bool>> truthTable = setTruthTable(mainPremisis, tempPremisis);
//		vector<bool> lastColumn = getLastColumn(tempPremisis, truthTable);
//		main.push_back(lastColumn);
//	}
//
//	cout << "\n\nMain Truth Table\n";
//	displayString(allPremisis);
//	display(main);
//	bool validate = checkValidation(main);
//
//	if (validate)
//	{
//		cout << "None\n";
//		write << "None\n";
//	}
//
//	cout << (validate ? "\nArgument is Valid\n" : "\nArgument is Not Valid\n");
//	write << (validate ? "\nArgument is Valid\n" : "\nArgument is Not Valid\n");
//
//	return 0;
//}
//
//vector<bool> getLastColumn(vector<string> prem, vector<vector<bool>> truthTable)
//{
//	vector<bool> lastColumn;
//
//	cout << endl << endl;
//	displayString(prem);
//	displayBool(prem, truthTable);
//
//	for (int i = 0; i < truthTable.size(); i++)
//	{
//		lastColumn.push_back(truthTable[i][prem.size() - 1]);
//	}
//
//	return lastColumn;
//}
//
//bool Implication(bool x, bool y)
//{
//	if (y == true)
//	{
//		return true;
//	}
//	else if (x == false and y == false)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//bool And(bool x, bool y)
//{
//	if (x == true and y == true)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//bool Or(bool x, bool y)
//{
//	if (x == true or y == true)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//bool Negation(bool x)
//{
//	if (x == true)
//	{
//		return false;
//	}
//	else
//	{
//		return true;
//	}
//}
//
//bool BiConditional(bool x, bool y)
//{
//	if (x == true and y == true)
//	{
//		return true;
//	}
//	else if (x == false and y == false)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//vector<vector<bool>> setTruthTable(vector<char>premisis, vector<string> hs)
//{
//	int rows = pow(2, premisis.size());
//	int column = hs.size();
//	vector<vector<bool>> truthTable(rows);
//
//	for (int i = 0; i < rows; i++)
//	{
//		truthTable[i].resize(column);
//
//		for (int j = 0; j < column; j++)
//		{
//			truthTable[i][j] = false;
//		}
//	}
//
//	int num = 2;
//	int count = 0;
//	bool check;
//
//	for (int i = 0; i < premisis.size(); i++)
//	{
//		count = rows / num;
//		check = true;
//
//		for (int j = 0; j < rows; j++)
//		{
//			if (count > 0)
//			{
//				truthTable[j][i] = check;
//				count--;
//			}
//			else if (count <= 0 and check == true)
//			{
//				count = (rows / num) - 1;
//				check = false;
//
//				truthTable[j][i] = check;
//			}
//			else if (count <= 0 and check == false)
//			{
//				count = (rows / num) - 1;
//				check = true;
//
//				truthTable[j][i] = check;
//			}
//		}
//
//		num *= 2;
//	}
//
//	int curr = -1;
//
//	for (int i = premisis.size(); i < truthTable[0].size(); i++)
//	{
//		curr = i;
//		string s1 = "", s2 = hs[curr];
//
//		int index1 = -1, index2 = -1;
//
//		for (int sIndex = curr - 1; sIndex >= 0; sIndex--)
//		{
//			s1 = hs[sIndex];
//
//			int found1 = s2.find(s1);
//			if (found1 != string::npos)
//			{
//				index1 = sIndex;
//				string s = "";
//
//				if (("(~" + s1 + ')') == s2)
//				{
//					for (int j = 0; j < rows; j++)
//					{
//						truthTable[j][i] = Negation(truthTable[j][index1]);
//					}
//				}
//
//				if ("(" + s1 + ")" == s2)
//				{
//					for (int j = 0; j < rows; j++)
//					{
//						truthTable[j][i] = truthTable[j][index1];
//					}
//				}
//
//				for (int ssIndex = curr - 1; ssIndex >= 0; ssIndex--)
//				{
//					string s3 = hs[ssIndex];
//					int found2 = s2.find(s3);
//					if (found2 != string::npos and found1 != found2)
//					{
//						index2 = ssIndex;
//
//						if (('(' + s1 + "^" + s3 + ')') == s2)
//						{
//							for (int j = 0; j < rows; j++)
//							{
//								truthTable[j][i] = And(truthTable[j][index1], truthTable[j][index2]);
//							}
//						}
//						else if (('(' + s1 + "~" + s3 + ')') == s2)
//						{
//							for (int j = 0; j < rows; j++)
//							{
//								truthTable[j][i] = And(truthTable[j][index1], truthTable[j][index2]);
//							}
//						}
//						else if (('(' + s1 + "V" + s3 + ')') == s2)
//						{
//							for (int j = 0; j < rows; j++)
//							{
//								truthTable[j][i] = Or(truthTable[j][index1], truthTable[j][index2]);
//							}
//						}
//						else if (('(' + s1 + "->" + s3 + ')') == s2)
//						{
//							for (int j = 0; j < rows; j++)
//							{
//								truthTable[j][i] = Implication(truthTable[j][index1], truthTable[j][index2]);
//							}
//						}
//						else if (('(' + s1 + "<->" + s3 + ')') == s2)
//						{
//							for (int j = 0; j < rows; j++)
//							{
//								truthTable[j][i] = BiConditional(truthTable[j][index1], truthTable[j][index2]);
//							}
//						}
//
//						else if (('(' + s3 + "^" + s1 + ')') == s2)
//						{
//							for (int j = 0; j < rows; j++)
//							{
//								truthTable[j][i] = And(truthTable[j][index2], truthTable[j][index1]);
//							}
//						}
//						else if (('(' + s3 + "~" + s1 + ')') == s2)
//						{
//							for (int j = 0; j < rows; j++)
//							{
//								truthTable[j][i] = And(truthTable[j][index2], truthTable[j][index1]);
//							}
//						}
//						else if (('(' + s3 + "V" + s1 + ')') == s2)
//						{
//							for (int j = 0; j < rows; j++)
//							{
//								truthTable[j][i] = Or(truthTable[j][index2], truthTable[j][index1]);
//							}
//						}
//						else if (('(' + s3 + "->" + s1 + ')') == s2)
//						{
//							for (int j = 0; j < rows; j++)
//							{
//								truthTable[j][i] = Implication(truthTable[j][index2], truthTable[j][index1]);
//							}
//						}
//						else if (('(' + s3 + "<->" + s1 + ')') == s2)
//						{
//							for (int j = 0; j < rows; j++)
//							{
//								truthTable[j][i] = BiConditional(truthTable[j][index2], truthTable[j][index1]);
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//
//	return truthTable;
//}
//
//bool checkValidation(vector<vector<bool>> truthTable)
//{
//	bool fal = true, check = true;
//	cout << "\n\nInvalid Arguments: \n";
//
//	for (int i = 0; i < truthTable[0].size(); i++)
//	{
//		check = true;
//
//		for (int j = 0; j < truthTable.size(); j++)
//		{
//			if (truthTable[j][i] == false && j != truthTable.size() - 1)
//			{
//				check = false;
//			}
//
//			if (check == true && j == truthTable.size() - 1 && truthTable[j][i] == false)
//			{
//				for (int curr = 0; curr < truthTable.size(); curr++)
//				{
//					cout << truthTable[curr][i] << "\t";
//				}
//				cout << endl;
//				fal = false;
//				check = false;
//			}
//		}
//	}
//
//	return (check && fal);
//}
//
//void displayBool(vector<string> prem, vector<vector<bool>> truthTable)
//{
//	cout << endl;
//	write << endl;
//
//	for (int i = 0; i < truthTable.size(); i++)
//	{
//		//for (int j = 0; j < truthTable[0].size() - prem.size(); j++)
//		for (int j = 0; j < truthTable[i].size(); j++)
//		{
//			cout << truthTable[i][j] << "\t";
//			write << truthTable[i][j] << ",";
//		}
//		cout << endl;
//		write << endl;
//	}
//}
//
//void display(vector<vector<bool>> truthTable)
//{
//	cout << endl;
//	write << endl;
//	for (int i = 0; i < truthTable[0].size(); i++)
//	{
//		for (int j = 0; j < truthTable.size(); j++)
//		{
//			cout << truthTable[j][i] << "\t";
//			write << truthTable[j][i] << ",";
//		}
//		cout << endl;
//		write << endl;
//	}
//}
//
//vector<string> seperateString(vector<char> pre, string rawString)
//{
//	vector<string> premisis;
//	vector<int> brackOpenPosition;
//	vector<int> brackClosePosition;
//
//	for (int i = 0; i < pre.size(); i++)
//	{
//		string temp = "";
//		temp += pre[i];
//
//		premisis.push_back(temp);
//	}
//
//	int brackOpenCount = 0, brackCloseCount = 0;
//	char openBrack = '(', closeBrack = ')';
//
//	for (int curr = 0; curr < rawString.length(); curr++)
//	{
//		if (rawString[curr] == openBrack)
//		{
//			brackOpenCount++;
//		}
//		else if (rawString[curr] == closeBrack)
//		{
//			brackCloseCount++;
//		}
//	}
//
//	if (brackOpenCount != brackCloseCount)
//	{
//		cout << "Error :: Bracket Missing";
//		exit(0);
//	}
//
//	int brackCount = brackOpenCount;
//
//	for (int curr = 0; curr < rawString.length(); curr++)
//	{
//		if (rawString[curr] == closeBrack && (searchResult(brackClosePosition, curr) == -1))
//		{
//			brackClosePosition.push_back(curr);
//
//			for (int i = curr; i >= 0; i--)
//			{
//				if (rawString[i] == openBrack && (searchResult(brackOpenPosition, i) == -1))
//				{
//					brackOpenPosition.push_back(i);
//					break;
//				}
//			}
//		}
//	}
//
//	string temp = "";
//
//	for (int curr = 0; curr < brackCount; curr++)
//	{
//		temp = "";
//
//		for (int i = brackOpenPosition[curr]; i <= brackClosePosition[curr]; i++)
//		{
//			temp += rawString[i];
//		}
//
//		premisis.push_back(temp);
//	}
//
//	return premisis;
//}
//
//vector<char> getPremisis(string main)
//{
//	vector<char> premisis;
//
//	for (int i = 0; i < main.length(); i++)
//	{
//		for (int curr = 97; curr <= 122; curr++)
//		{
//			char temp1 = curr, temp2 = main[i];
//
//			if (temp1 == temp2 && searchResult(premisis, temp2) == -1)
//			{
//				premisis.push_back(temp2);
//			}
//		}
//	}
//
//	for (int i = 0; i < premisis.size() - 1; i++)
//	{
//		if (premisis[i] > premisis[i + 1])
//		{
//			char temp = premisis[i];
//			premisis[i] = premisis[i + 1];
//			premisis[i + 1] = temp;
//		}
//	}
//
//	return premisis;
//}
//
//int searchResult(vector<char> arr, char k)
//{
//	vector<char>::iterator it;
//	it = find(arr.begin(), arr.end(), k);
//
//	if (it != arr.end())
//	{
//		return (it - arr.begin());
//	}
//	else
//	{
//		return -1;
//	}
//}
//
//int searchResult(vector<string> arr, string k)
//{
//	vector<string>::iterator it;
//	it = find(arr.begin(), arr.end(), k);
//
//	if (it != arr.end())
//	{
//		return (it - arr.begin());
//	}
//	else
//	{
//		return -1;
//	}
//}
//
//int searchResult(vector<int> arr, int k)
//{
//	vector<int>::iterator it;
//	it = find(arr.begin(), arr.end(), k);
//
//	if (it != arr.end())
//	{
//		return (it - arr.begin());
//	}
//	else
//	{
//		return -1;
//	}
//}
//
//void displayChar(vector<char> premisis)
//{
//	for (int curr = 0; curr < premisis.size(); curr++)
//	{
//		cout << premisis[curr] << "\t";
//	}
//}
//
//void displayString(vector<string> premisis)
//{
//	cout << endl;
//	write << endl;
//
//	for (int curr = 0; curr < premisis.size(); curr++)
//	{
//		cout << premisis[curr] << "\t";
//		write << premisis[curr] << ",";
//	}
//
//	write << endl;
//	cout << endl;
//}
//
//bool checkTruthTableEquivalance(vector<char> prem, vector<vector<bool>>LHS, vector<vector<bool>>RHS)
//{
//
//	for (int i = 0; i < LHS.size(); i++)
//	{
//		int indexLHS = LHS[i].size() - 1;
//		int indexRHS = RHS[i].size() - 1;
//
//		if (LHS[i][indexLHS] != RHS[i][indexRHS])
//		{
//			return false;
//		}
//	}
//
//	return true;
//}