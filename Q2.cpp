//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//
//void display(vector<int> causingVertices)
//{
//	if (causingVertices.size() > 1)
//	{
//		cout << "\nVertices causing conflict: ";
//	}
//	else
//	{
//		cout << "Vertex causing conflict: ";
//	}
//
//	for (int j = 0; j < causingVertices.size(); j++)
//	{
//		cout << causingVertices[j];
//
//		if (j < causingVertices.size() - 1)
//		{
//			cout << ", ";
//		}
//	}
//	cout << endl;
//}
//
//vector<vector<int>> matrixToAdjList(vector<vector<int>> graph)
//{
//	vector<vector<int>> adj_list(graph.size());
//
//	for (int i = 0; i < graph.size(); i++)
//	{
//		adj_list[i].push_back(i);
//
//		for (int j = 0; j < graph[i].size(); j++)
//		{
//			if (graph[i][j] == 1)
//			{
//				adj_list[i].push_back(j);
//			}
//		}
//	}
//	return adj_list;
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
//int main()
//{
//	int condition;
//
//	cout << "Enter 1. for Adjacency Matrix\nEnter 2. for Adjacency List\nInput: ";
//	cin >> condition;
//
//	vector<vector<int>> adj;
//	vector<int> causingVertices;
//
//	if (condition == 1)
//	{
//		vector<vector<int>> matrix;
//
//		int n;
//		cout << "\n\t\t***ADJACENCY MATRIX***\n\n";
//		cout << "Enter the number of vertices: ";
//		cin >> n;
//
//		cout << "\nEnter the Adjacency: "  <<endl;
//		for (int i = 0; i < n; i++) 
//		{
//			vector<int> row;
//			for (int j = 0; j < n; j++) 
//			{
//				int value;
//				cout << "*Enter 1 for CONNECTED* \n*Enter 0 for NOT CONNECTED*\n\n";
//				cout << "Is the VERTEX " << j << " connected to " << i <<" : ";
//				cin >> value;
//				row.push_back(value);
//			}
//
//			matrix.push_back(row);
//		}
//
//		adj = matrixToAdjList(matrix);
//
//		//vector<vector<int>> matrix =
//		//{
//		//	// Project Test Case 1 : False
//		//		//1,2,3,4,5,6,7,8,9,10,11
//		//	/*1*/{0,0,1,0,1,0,0,1,0,0,0},
//		//	/*2*/{0,0,1,0,0,0,0,0,1,0,1},
//		//	/*3*/{1,1,0,1,0,0,0,0,0,0,0},
//		//	/*4*/{0,0,1,0,0,1,0,0,0,1,0},
//		//	/*5*/{1,0,0,0,0,1,1,0,0,0,0},
//		//	/*6*/{0,0,0,1,1,0,0,0,1,0,0},
//		//	/*7*/{0,0,0,0,1,0,0,0,0,1,0},
//		//	/*8*/{1,0,0,0,0,0,0,0,1,1,0},
//		//	/*9*/{0,1,0,0,0,1,0,1,0,0,0},
//		//	/*10*/{0,0,0,1,0,0,1,1,0,0,0},
//		//	/*11*/{0,1,0,0,0,0,1,0,0,0,0},
//
//		//	// Project Test Case 2 : True
//		//		//1,2,3,4,5,6,7,8,9,10,11
//		//	///*1*/{0,1,0,0,0,0,0,0,1,1,0},
//		//	///*2*/{1,0,1,0,0,1,0,0,0,0,0},
//		//	///*3*/{0,1,0,1,0,0,0,1,0,0,0},
//		//	///*4*/{0,0,1,0,1,0,0,0,0,0,1},
//		//	///*5*/{0,0,0,1,0,1,0,0,1,0,0},
//		//	///*6*/{0,1,0,0,1,0,1,0,0,0,0},
//		//	///*7*/{0,0,0,0,0,1,0,1,0,0,1},
//		//	///*8*/{0,0,1,0,0,0,1,0,1,0,0},
//		//	///*9*/{1,0,0,0,1,0,0,1,0,0,0},
//		//	///*10*/{1,0,0,0,0,0,0,0,0,0,1},
//		//	///*11*/{0,0,0,1,0,0,1,0,0,1,0},
//		//	
//		//	// Test Case 1 : True
//		//	/*{0, 1, 0, 1},
//		//	{1, 0, 1, 0},
//		//	{0, 1, 0, 1},
//		//	{1, 0, 1, 0}*/
//
//		//	// Test Case 2 : False
//		//	/*{0, 1, 1, 0},
//		//	{1, 0, 1, 0},
//		//	{1, 1, 0, 1},
//		//	{0, 0, 1, 0}*/
//
//		//	// Test Case 3 : True
//		//	/*{0, 1, 0, 1},
//		//	{1, 0, 1, 0},
//		//	{0, 1, 0, 1},
//		//	{1, 0, 1, 0},
//		//	{0, 0, 0, 0}*/
//
//		//	// Test Case 4 : False
//		//	/*{0, 1, 1, 0, 0},
//		//	{1, 0, 1, 0, 0},
//		//	{1, 1, 0, 1, 0},
//		//	{0, 0, 1, 0, 1},
//		//	{0, 0, 0, 1, 0}*/
//
//		//};
//		//adj = matrixToAdjList(matrix);
//	}
//	else
//	{
//		vector<vector<int>> adjList;
//
//		int n;
//		cout << "\t\t***ADJACENCY LIST***\n\n";
//		cout << "Enter the number of vertices for the Adjacency List : ";
//		cin >> n;
//
//		cout << "\nEnter the Adjacency : " << endl;
//		for (int i = 0; i < n; i++)
//		{
//			vector<int> list;
//			int m;
//			cout << "Enter the number of Vertices adjacent to Vertex " << i + 1 << " : ";
//			cin >> m;
//			cout << "Enter the Vertices adjacent to Vertex " << i + 1 << " : ";
//			for (int j = 0; j < m; j++) 
//			{
//				int val;
//				cin >> val;
//				list.push_back(val);
//			}
//
//			adjList.push_back(list);
//		}
//
//		adj = adjList;
//
//		//vector<vector<int>> adjList
//		//{
//		//	/*{1,3},
//		//	{0,2},
//		//	{1,3},
//		//	{0,2},*/
//
//		//	/*{0, 1},
//		//	{1, 2},
//		//	{2, 0}*/
//
//		//	/*{0,1},
//		//	{1,2},
//		//	{2,3},
//		//	{3,0}*/
//
//		//	/*{0, 5, 6, 7, 8},
//		//	{1, 6, 7, 8 ,9},
//		//	{2, 5, 6, 7, 9},
//		//	{3, 5, 6, 8, 9},
//		//	{4, 5, 7, 8, 9}*/
//
//		//	/*{0, 1, 1, 0, 0},
//		//	{1, 0, 1, 0, 0},
//		//	{1, 1, 0, 0, 1},
//		//	{0, 0, 0, 0, 1},
//		//	{0, 0, 1, 1, 0}*/
//
//		//	/*{1,2},
//		//	{0,2},
//		//	{0,1,3},
//		//	{2}*/
//
//		//	/*{1,2},
//		//	{0,2},
//		//	{0, 1,3},
//		//	{2,4},
//		//	{3}*/
//
//		//	{0,1,2},
//		//	{1,0,2},
//		//	{2,0,1,3},
//		//	{3,2,4},
//		//	{4,3,5},
//		//	{5,4}
//		//};
//
//	}
//
//	vector<int> arr1;
//	vector<int> arr2;
//	bool bipart = true;
//
//	for (int i = 0; i < adj.size(); i++)
//	{
//		int indexMN1 = searchResult(arr1, adj[i][0]);
//		int indexMN2 = searchResult(arr2, adj[i][0]);
//
//		if (indexMN1 == -1 && indexMN2 == -1)
//		{
//			// Not Found the item
//			arr1.push_back(adj[i][0]);
//		}
//		else if (indexMN1 != -1 && indexMN2 != -1)
//		{
//			// Found the item
//			bipart = false;
//
//			if (searchResult(causingVertices, adj[i][0]) == -1)
//			{
//				causingVertices.push_back(adj[i][0]);
//			}
//		}
//
//		for (int j = 1; j < adj[i].size(); j++)
//		{
//			int indexMM1 = searchResult(arr1, adj[i][j]);
//			int indexMM2 = searchResult(arr2, adj[i][j]);
//
//			indexMN1 = searchResult(arr1, adj[i][0]);
//			indexMN2 = searchResult(arr2, adj[i][0]);
//
//			if (indexMM1 != -1 && indexMM2 != -1)
//			{
//				// Found the item
//				bipart = false;
//
//				if (searchResult(causingVertices, adj[i][j]) == -1)
//				{
//					causingVertices.push_back(adj[i][j]);
//				}
//			}
//			else if (indexMN1 != -1 || indexMN2 != -1)
//			{
//				// Found the item
//
//				if (indexMN1 != -1 && indexMN2 == -1 && indexMM2 == -1)
//				{
//					arr2.push_back(adj[i][j]);
//				}
//				else if (indexMN2 != -1 && indexMN1 == -1 && indexMM1 == -1)
//				{
//					arr1.push_back(adj[i][j]);
//				}
//				
//				indexMM1 = searchResult(arr1, adj[i][j]);
//				indexMM2 = searchResult(arr2, adj[i][j]);
//				
//				if (indexMM1 != -1 && indexMM2 != -1)
//				{
//					bipart = false; 
//					
//					if (searchResult(causingVertices, adj[i][j]) == -1)
//					{
//						causingVertices.push_back(adj[i][j]);
//					}
//				}
//			}
//			else if (indexMM1 == -1 && indexMM2 == -1)
//			{
//				// Not Found the item
//				arr2.push_back(adj[i][j]);
//			}
//		}
//	}
//
//	cout << endl << "Vertix 1 List: ";
//
//	for (int i = 0; i < arr1.size(); i++)
//	{
//		cout << arr1[i] << " ";
//	}
//	cout << endl << "Vertix 2 List: ";
//
//	for (int i = 0; i < arr2.size(); i++)
//	{
//		cout << arr2[i] << " ";
//	}
//	cout << endl;
//
//	cout << "\nIs Graph Bipartite: " << (bipart == 1? "Yes" : "No") << endl;
//
//	if (bipart == false)
//	{
//		display(causingVertices);
//	}
//
//	return 0;
//}