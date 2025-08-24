#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
#include <map>
using namespace std;

class edge
{
public:
    int next;
    double dist;

    edge(int next, double dist)
    {
        this->next = next;
        this->dist = dist;
    }
};

class driver
{
public:
    string name;
    string carname;
    string phoneno;
    string plateno;
    double price;

    driver(string name, string carname, string phoneno, string plateno, double price)
    {
        this->name = name;
        this->carname = carname;
        this->plateno = plateno;
        this->phoneno = phoneno;
        this->price = price;
    }
};

class dijkstra
{
public:
    int value;
    double distance;
    string path;

    dijkstra(int value, double distance, string path)
    {
        this->value = value;
        this->distance = distance;
        this->path = path;
    }
     bool operator>(const dijkstra &other) const
    {
        return this->distance > other.distance;
    }
};

class stops
{

public:
    int num;
    double cost;
    int visitedstops;

    stops(int num, double cost, int visitedstops)
    {
        this->num = num;
        this->cost = cost;
        this->visitedstops = visitedstops;
    }


    bool operator>(const stops &other) const
    {
        return this->cost > other.cost;
    }
};

class prims
{

public:
    int val;
    double cost1;

    prims(int val, double cost1)
    {
        this->val = val;
        this->cost1 = cost1;
    }

    bool operator>(const prims &other) const
    {
        return this->cost1 > other.cost1;
    }
};

vector<vector<edge>> mumbai(12, vector<edge>());
vector<vector<edge>> indore(12, vector<edge>());
vector<vector<edge>> ahmedabad(12, vector<edge>());

unordered_map<string, int> mum;
unordered_map<string, int> idr;
unordered_map<string, int> ahm;
unordered_map<int, string> mum1;
unordered_map<int, string> idr1;
unordered_map<int, string> ahm1;
unordered_map<string, vector<vector<edge>>> map1;
unordered_map<string, unordered_map<string, int>> map2;
unordered_map<string, unordered_map<int, string>> map3;

unordered_map<int, vector<driver>> m1;
unordered_map<int, vector<driver>> m2;
unordered_map<int, vector<driver>> m3;
unordered_map<string, unordered_map<int, vector<driver>>> drivermap;

void mumbaidriver()
{
    driver d1("Mohan", "Scorpio", "9988992345", "MH2CK81699", 8.88);
    driver d2("Suresh","Tata Indica", "9988792345", "MH3C876997", 6.88);
    driver d3("Sukesh", "Hyundai I20", "9988922345", "MH2CT81699", 5.88);
    m1[0].push_back(d1);
    m1[0].push_back(d2);
    m1[0].push_back(d3);
    driver d4("Mahesh", "Hyundai Accent", "7988992345", "MH2TK81799", 8.88);
    driver d5("Rohit", "Tata Sumo", "6988992345", "MH1C876097", 7.88);
    driver d6("Umang", "Tata Nano", "8988992345", "MH2FT81899", 4.58);
    m1[1].push_back(d4);
    m1[1].push_back(d5);
    m1[1].push_back(d6);
    driver d7("Aaditya", "Mahindra XUV 700", "9988992345", "MH5CK81699", 12.00);
    m1[2].push_back(d7);
    driver d8("Sudhanshu", "Hyundai I10 Grand", "9966992345", "MH2TK41799", 6.00);
    driver d9("Rakesh", "Hyundai Creta", "7988992345", "MH1C876667", 13.00);
    m1[3].push_back(d8);
    m1[3].push_back(d9);
    driver s1("Ramesh", "Wagnor Lxi", "6988992345", "MH1C859097", 9.00);
    driver s2("Gopal", "Maruti Suzuki Swift", "7988992345", "MH2FU01899", 8.97);
    m1[4].push_back(s1);
    m1[4].push_back(s2);
    driver s3("Vinod", "Mahindra KUV", "9955992345", "MH5CK87691", 16.00);
    m1[5].push_back(s3);
    driver s4("Sharad", "Hyundai Santro", "9999992345", "MH2TK41999", 8.12);
    driver s5("Sharat", "Celerio", "9988992388", "MH3C076667", 9.67);
    m1[6].push_back(s4);
    m1[6].push_back(s5);
    driver s6("Mohak", "Mahindra TUV 300", "9954992345", "MH5CH87671", 14.00);
    m1[7].push_back(s6);
    driver s7("Dhruv", "Hyundai Santro", "9990992345", "MH2TK41999", 8.12);
    driver s8("Dheeraj", "Celerio", "7788992345", "MH3C076667", 9.67);
    m1[8].push_back(s7);
    m1[8].push_back(s8);
    driver h1("Kapil", "Scorpio", "8888992345", "MH2CK81699", 8.88);
    driver h2("Atharva", "Tata Indica", "8088992345", "MH3C876997", 6.88);
    driver h3("Ishaan", "Hyundai I20", "9088992345", "MH2CT81699", 5.88);
    m1[9].push_back(h1);
    m1[9].push_back(h2);
    m1[9].push_back(h3);
    driver g1("Praveen", "Scorpio", "7988992345", "MH2CK81699", 8.88);
    driver g2("Mandeep", "Tata Nano", "8988992345", "MH4C876907", 3.88);
    driver g3("Ajay", "XUV 500", "7688992345", "MH2CH81689", 12.88);
    m1[10].push_back(g1);
    m1[10].push_back(g2);
    m1[10].push_back(g3);
    driver g4("Sumit", "Tata Harrier", "7766992345", "MH9CH86671", 12.00);
    m1[11].push_back(g4);
    drivermap["mumbai"] = m1;
}

void indoredriver()
{
    driver d1("Vikram", "Scorpio", "9988992345", "MP2CK81699", 8.88);
    driver d2("Aarav", "Tata Indica", "9988792345", "MP3C876997", 6.88);
    driver d3("Arjun", "Hyundai I20", "9988922345", "MP2CT81699", 5.88);
    m2[0].push_back(d1);
    m2[0].push_back(d2);
    m2[0].push_back(d3);
    driver d4("Dev", "Hyundai Accent", "7988992345", "MP2TK81799", 8.88);
    driver d5("Kabir", "Tata Sumo", "6988992345", "MP1C876097", 7.88);
    driver d6("Deepak", "Tata Nano", "8988992345", "MP2FT81899", 4.58);
    m2[1].push_back(d4);
    m2[1].push_back(d5);
    m2[1].push_back(d6);
    driver d7("Raj", "Mahindra XUV 700", "9988992345", "MP5CK81699", 12.00);
    m2[2].push_back(d7);
    driver d8("Sanjay", "Hyundai I10 Grand", "9966992345", "MP2TK41799", 6.00);
    driver d9("Manoj", "Hyundai Creta", "7988992345", "MP1C876667", 13.00);
    m2[3].push_back(d8);
    m2[3].push_back(d9);
    driver s1("Ashutosh", "Wagnor Lxi", "6988992345", "MP1C859097", 9.00);
    driver s2("Shashank", "Maruti Suzuki Swift", "7988992345", "MP2FU01899", 8.97);
    m2[4].push_back(s1);
    m2[4].push_back(s2);
    driver s3("Monty", "Mahindra KUV", "9955992345", "MP5CK87691", 16.00);
    m2[5].push_back(s3);
    driver s4("Mahendra", "Hyundai Santro", "9999992345", "MP2TK41999", 8.12);
    driver s5("Rahul", "Celerio", "9988992388", "MP3C076667", 9.67);
    m2[6].push_back(s4);
    m2[6].push_back(s5);
    driver s6("Kartik", "Mahindra TUV 300", "9954992345", "MP5CH87671", 14.00);
    m2[7].push_back(s6);
    driver s7("Nitin", "Hyundai Santro", "9990992345", "MP2TK41999", 8.12);
    driver s8("Harish", "Celerio", "7788992345", "MP3C076667", 9.67);
    m2[8].push_back(s7);
    m2[8].push_back(s8);
    driver h1("Satish", "Scorpio", "8888992345", "MP2CK81699", 8.88);
    driver h2("Vishal", "Tata Indica", "8088992345", "MP3C876997", 6.88);
    driver h3("Manish", "Hyundai I20", "9088992345", "MP2CT81699", 5.88);
    m2[9].push_back(h1);
    m2[9].push_back(h2);
    m2[9].push_back(h3);
    driver g1("Arvind", "Scorpio", "7988992345", "MP2CK81699", 8.88);
    driver g2("Yash", "Tata Nano", "8988992345", "MP4C876907", 3.88);
    driver g3("Jatin", "XUV 500", "7688992345", "MP2CH81689", 12.88);
    m2[10].push_back(g1);
    m2[10].push_back(g2);
    m2[10].push_back(g3);
    driver g4("Akshay", "Tata Harrier", "7766992345", "MP9CH86671", 12.00);
    m2[11].push_back(g4);
    drivermap["indore"] = m2;
}

void ahmedabaddriver()
{
    driver d1("Abhinav", "Scorpio", "9988992345", "GJ2CK81699", 8.88);
    driver d2("Tarun", "Tata Indica", "9988792345", "GJ3C876997", 6.88);
    driver d3("Girish", "Hyundai I20", "9988922345", "GJ2CT81699", 5.88);
    m3[0].push_back(d1);
    m3[0].push_back(d2);
    m3[0].push_back(d3);
    driver d4("Chetan", "Hyundai Accent", "7988992345", "GJ2TK81799", 8.88);
    driver d5("Sandeep", "Tata Sumo", "6988992345", "GJ1C876097", 7.88);
    driver d6("Suraj", "Tata Nano", "8988992345", "GJ2FT81899", 4.58);
    m3[1].push_back(d4);
    m3[1].push_back(d5);
    m3[1].push_back(d6);
    driver d7("Lokesh", "Mahindra XUV 700", "9988992345", "GJ5CK81699", 12.00);
    m3[2].push_back(d7);
    driver d8("Pranav", "Hyundai I10 Grand", "9966992345", "GJ2TK41799", 6.00);
    driver d9("Jay", "Hyundai Creta", "7988992345", "GJ1C876667", 13.00);
    m3[3].push_back(d8);
    m3[3].push_back(d9);
    driver s1("Vijay", "Wagnor Lxi", "6988992345", "GJ1C859097", 9.00);
    driver s2("Vinay", "Maruti Suzuki Swift", "7988992345", "GJ2FU01899", 8.97);
    m3[4].push_back(s1);
    m3[4].push_back(s2);
    driver s3("Dheeraj", "Mahindra KUV", "9955992345", "GJ5CK87691", 16.00);
    m3[5].push_back(s3);
    driver s4("Pankaj", "Hyundai Santro", "9999992345", "GJ2TK41999", 8.12);
    driver s5("Pradeep", "Celerio", "9988992388", "GJ3C076667", 9.67);
    m3[6].push_back(s4);
    m3[6].push_back(s5);
    driver s6("Shubham", "Mahindra TUV 300", "9954992345", "GJ5CH87671", 14.00);
    m3[7].push_back(s6);
    driver s7("Yuvraj", "Hyundai Santro", "9990992345", "GJ2TK41999", 8.12);
    driver s8("Sagar", "Celerio", "7788992345", "GJ3C076667", 9.67);
    m3[8].push_back(s7);
    m3[8].push_back(s8);
    driver h1("Chirag", "Scorpio", "8888992345", "KA2CK81699", 8.88);
    driver h2("Aakash", "Tata Indica", "8088992345", "KA3C876997", 6.88);
    driver h3("Dhawal", "Hyundai I20", "9088992345", "KA2CT81699", 5.88);
    m3[9].push_back(h1);
    m3[9].push_back(h2);
    m3[9].push_back(h3);
    driver g1("Anshul", "Scorpio", "7988992345", "GJ2CK81699", 8.88);
    driver g2("Abhishek", "Tata Nano", "8988992345", "GJ4C876907", 3.88);
    driver g3("Amol", "XUV 500", "7688992345", "GJ2CH81689", 12.88);
    m3[10].push_back(g1);
    m3[10].push_back(g2);
    m3[10].push_back(g3);
    driver g4("Bharat", "Tata Harrier", "7766992345", "GJ9CH86671", 12.00);
    m3[11].push_back(g4);
    drivermap["ahmedabad"] = m3;
}

void addedge(int v1, int v2, double weight, vector<vector<edge>> &graph)
{
    edge e1(v2, weight);
    graph[v1].push_back(e1);
    edge e2(v1, weight);
    graph[v2].push_back(e2);
    return;
}

void graphs()
{
    addedge(0, 1, 2.4, mumbai);
    addedge(0, 10, 12, mumbai);
    addedge(0, 7, 4.7, mumbai);
    addedge(0, 6, 7.5, mumbai);
    addedge(1, 10, 14, mumbai);
    addedge(1, 7, 13, mumbai);
    addedge(7, 8, 14, mumbai);
    addedge(7, 6, 3.1, mumbai);
    addedge(6, 8, 12, mumbai);
    addedge(6, 4, 29, mumbai);
    addedge(2, 5, 21, mumbai);
    addedge(2, 8, 6.4, mumbai);
    addedge(2, 10, 8.8, mumbai);
    addedge(2, 3, 3.1, mumbai);
    addedge(5, 3, 15, mumbai);
    addedge(5, 4, 30, mumbai);
    addedge(10, 3, 7.7, mumbai);
    addedge(3, 9, 2.2, mumbai);
    addedge(3, 4, 17, mumbai);
    addedge(4, 9, 17, mumbai);
    addedge(4, 11, 20, mumbai);
    addedge(9, 11, 4.2, mumbai);

    addedge(0, 1, 7.7, indore);
    addedge(0, 2, 8.5, indore);
    addedge(1, 2, 9.9, indore);
    addedge(1, 4, 11, indore);
    addedge(1, 7, 36, indore);
    addedge(2, 11, 30, indore);
    addedge(2, 8, 6.9, indore);
    addedge(2, 5, 17, indore);
    addedge(2, 4, 3.8, indore);
    addedge(2, 3, 9.2, indore);
    addedge(3, 9, 61, indore);
    addedge(3, 10, 45, indore);
    addedge(5, 4, 14, indore);
    addedge(4, 6, 7.9, indore);
    addedge(4, 8, 8, indore);
    addedge(8, 7, 21, indore);
    addedge(7, 6, 40, indore);
    addedge(6, 10, 45, indore);
    addedge(6, 9, 63, indore);
    addedge(9, 10, 63, indore);

    addedge(0, 1, 128, ahmedabad);
    addedge(0, 2, 147, ahmedabad);
    addedge(0, 1, 147, ahmedabad);
    addedge(1, 2, 26, ahmedabad);
    addedge(1, 6, 55, ahmedabad);
    addedge(2, 3, 4, ahmedabad);
    addedge(2, 4, 63, ahmedabad);
    addedge(2, 6, 33, ahmedabad);
    addedge(2, 5, 15, ahmedabad);
    addedge(5, 10, 87, ahmedabad);
    addedge(5, 11, 275, ahmedabad);
    addedge(5, 9, 265, ahmedabad);
    addedge(4, 6, 44, ahmedabad);
    addedge(6, 8, 287, ahmedabad);
    addedge(4, 7, 87, ahmedabad);
    addedge(3, 8, 366, ahmedabad);
    addedge(3, 7, 224, ahmedabad);
    addedge(10, 3, 147, ahmedabad);
    addedge(7, 11, 132, ahmedabad);
}

void connection()
{
    mum["AndheriEast"] = 1;
    mum["AndheriWest"] = 0;
    mum["Worli"] = 10;
    mum["Juhu"] = 7;
    mum["Bandra"] = 2;
    mum["Colaba"] = 8;
    mum["Santacruz"] = 6;
    mum["Mulund"] = 5;
    mum["Borivali"] = 3;
    mum["Chembur"] = 4;
    mum["Kurla"] = 11;
    mum["Malabarhills"] = 9;
    mum1[1] = "AndheriEast";
    mum1[0] = "AndheriWest";
    mum1[10] = "Worli";
    mum1[7] = "Juhu";
    mum1[2] = "Bandra";
    mum1[8] = "Colaba";
    mum1[6] = "Santacruz";
    mum1[5] = "Mulund";
    mum1[3] = "Borivali";
    mum1[4] = "Chembur";
    mum1[11] = "Kurla";
    mum1[9] = "Malabarhills";

    idr["VijayNagar"] = 0;
    idr["SarafaBazaar"] = 1;
    idr["Rajwada"] = 2;
    idr["ShivajiNagar"] = 3;
    idr["NehruNagar"] = 4;
    idr["SubhashNagar"] = 5;
    idr["MaheshNagar"] = 6;
    idr["Mhow"] = 7;
    idr["Rhow"] = 8;
    idr["Khandwa"] = 9;
    idr["AirpotRoad"] = 10;
    idr["Depalpur"] = 11;
    idr1[0] = "VijayNagar";
    idr1[1] = "SarafaBazaar";
    idr1[2] = "Rajwada";
    idr1[3] = "ShivajiNagar";
    idr1[4] = "NehruNagar";
    idr1[5] = "SubhashNagar";
    idr1[6] = "MaheshNagar";
    idr1[7] = "Mhow";
    idr1[8] = "Rhow";
    idr1[9] = "Khandwa";
    idr1[10] = "AirpotRoad";
    idr1[11] = "Depalpur";

    ahm["Viramgam"] = 0;
    ahm["Sanand"] = 1;
    ahm["Ghatlodia"] = 2;
    ahm["Vejalpur"] = 3;
    ahm["Vatva"] = 4;
    ahm["Ellisbridge"] = 5;
    ahm["Naranpura"] = 6;
    ahm["Nikol"] = 7;
    ahm["Naroda"] = 8;
    ahm["Dariapur"] = 9;
    ahm["Maninagar"] = 10;
    ahm["Sabarmati"] = 11;
    ahm1[0] = "Viramgam";
    ahm1[1] = "Sanand";
    ahm1[2] = "Ghatlodia";
    ahm1[3] = "Vejalpur";
    ahm1[4] = "Vatva";
    ahm1[5] = "Ellisbridge";
    ahm1[6] = "Naranpura";
    ahm1[7] = "Nikol";
    ahm1[8] = "Naroda";
    ahm1[9] = "Dariapur";
    ahm1[10] = "Maninagar";
    ahm1[11] = "Sabarmati";

    map1["mumbai"] = mumbai;
    map1["indore"] = indore;
    map1["ahmedabad"] = ahmedabad;

    map2["mumbai"] = mum;
    map2["indore"] = idr;
    map2["ahmedabad"] = ahm;
    map3["mumbai"] = mum1;
    map3["indore"] = idr1;
    map3["ahmedabad"] = ahm1;
}

void printPaths(int u, int d, vector<vector<edge>> city, vector<bool> visited, string result, unordered_map<int, string> getcity, int &count, double distance)
{

    visited[u] = true;

    if (u == d)
    {
        count++;
        cout<<count<<"  :-  "<<result<<" "<<distance<<"KM" "\n\n";
        return;
    }

    for (int i = 0; i < city[u].size(); i++)
    {
        edge e1 = city[u][i];
        if (visited[e1.next] == false)
            printPaths(e1.next, d, city, visited, (result + "->" + getcity[e1.next]), getcity, count, distance + e1.dist);
    }

    visited[u] = false;
}



void printAll(int s, int d, vector<vector<edge>> &city, unordered_map<int, string> &getcity)
{
    int V = city.size();
    vector<bool> visited(V, false);
    string result = getcity[s];
    int count = 0;
    double distance = 0;
    printPaths(s, d, city, visited, result, getcity, count, distance);
}

void findstoppath(int src, int des, vector<vector<edge>> &city, int totalstops, unordered_map<string, int> getid, unordered_map<int, string> getcity, int visitedstops, double currentdistance, vector<bool> visited, string result, map<double, string> &m1)
{
    visited[src] = true;

    if (src == des && visitedstops == (1 << totalstops) - 1)
    {
        m1[currentdistance] = result;
        return;
    }

    for (int i = 0; i < city[src].size(); i++)
    {
        edge e1 = city[src][i];
        string city1 = getcity[e1.next];
        int newvisitedstops = visitedstops;
        if (visited[e1.next] == false)
        {

            if (getid.find(city1) != getid.end())
            {
                newvisitedstops = ((visitedstops) | (1 << getid[city1]));
            }

            findstoppath(e1.next, des, city, totalstops, getid, getcity, newvisitedstops, currentdistance + e1.dist, visited, result + "->" + getcity[e1.next], m1);
        }
    }

    visited[src] = false;
}

void dijkstraalgo(int src, int dsc, vector<vector<edge>> &city, unordered_map<int, string> &getcity)
{

    priority_queue<dijkstra, vector<dijkstra>, greater<dijkstra>> pq;
    dijkstra d1(src, 0, getcity[src]);
    vector<bool> visited(city.size(), false);
    int count = 1;
    pq.push(d1);
    double maxcost = INT_MAX;
    while(!pq.empty())
    {

        dijkstra d1 = pq.top();
        pq.pop();

        if (d1.value == dsc && d1.distance <= maxcost)
        {
            cout<<"Path "<<count<<"-: "<<d1.path<<" - "<<d1.distance<<" KM"<< "\n\n";
            maxcost = d1.distance;
            count++;
            continue;
        }

        if(visited[d1.value] == true)
            continue;

        visited[d1.value] = true;

        for(int i = 0; i < city[d1.value].size(); i++)
        {

            edge e1 = city[d1.value][i];

            if(visited[e1.next] != true)
            {

                dijkstra v1(e1.next, e1.dist + d1.distance, d1.path + "->" + getcity[e1.next]);
                pq.push(v1);
            }
        }
    }
}


void Primsalgo(int src, vector<vector<edge>> &city, unordered_map<int, string> &getcity)
{

    priority_queue<prims, vector<prims>, greater<prims>> pq;
    prims d1(src, 0);
    vector<bool> visited(city.size(), false);
    double count = 0;
    int visit = 0;
    pq.push(d1);
    cout<<"\n";

    while(!pq.empty())
    {

        prims d1 = pq.top();
        pq.pop();

        if (visited[d1.val] == true)
            continue;

        count += d1.cost1;
        visit++;

        cout<<getcity[d1.val]<<"{ "<<d1.cost1<<" }"<< "-> ";

        if(visit == city.size())
        {
            cout<<"\n              TOTAL COST OF VISITING IS"<<"\n";
            cout<<"                  "<<count<<" KM \n";
            break;
        }

        visited[d1.val] = true;

        for(int i = 0; i < city[d1.val].size(); i++)
        {

            edge e1 = city[d1.val][i];

            if(visited[e1.next] != true)
            {

                prims v1(e1.next, e1.dist);
                pq.push(v1);
            }
        }
    }
}


void driverinfo(int src, unordered_map<int, vector<driver>> d)
{

    vector<driver> d1 = d[src];
    int count = 0;

    for (int i = 0; i < d1.size(); i++)
    {
        count++;
        driver s = d1[i];
        cout<<"\n";
        cout<<count << "\n";
        cout<<"driver name"<<" -" <<s.name<<"\n";
        cout<<"Driver car name"<<" - "<<s.carname<<"\n";
        cout<<"Driver car no plate"<<" - "<<s.plateno<<"\n";
        cout<<"Driver Phone number"<<" - "<<s.phoneno<<"\n";
        cout << "Driver charges for per km   "<<s.price<<" per km ";
    }
}

void intro()
{
    char c;
    c = 92;
    system("color 5f");
    for(int i = 0; i<312; i++)
        cout<<"*";
    cout<<endl;
    for(int i = 0; i<40; i++)
        cout<<" ";
    for(int i = 0; i<39; i++)
        cout<<"-*";
    cout<<endl;
    for(int i = 0; i<40; i++)
        cout<<" ";
    cout<<"|                                                                            |"<<endl;
    for(int i = 0; i<40; i++)
        cout<<" ";
    cout<<"|                                                                            |"<<endl;
    for(int i = 0; i<40; i++)
        cout<<" ";
    cout<<"|                                   ___       ___    __                      |"<<endl;
    for(int i = 0; i<40; i++)
        cout<<" ";
    cout<<"|              |"<<c<<"  |   /"<<c<<" "<<c<<"    / | | __   /"<<c<<"   |  | |  | |"<<c<<"  |               |"<<endl;
    for(int i = 0; i<40; i++)
        cout<<" ";
    cout<<"|              | "<<c<<" |  /--"<<c<<" "<<c<<"  /  | |  |  /--"<<c<<"  |  | |  | | "<<c<<" |               |"<<endl;
    for(int i = 0; i<40; i++)
        cout<<" ";
    cout<<"|              |  "<<c<<"| /    "<<c<<" "<<c<<"/   | |__| /    "<<c<<" |  | |__| |  "<<c<<"|               |"<<endl;
    for(int i = 0; i<40; i++)
        cout<<" ";
    cout<<"|                                                                            |"<<endl;
    for(int i = 0; i<40; i++)
        cout<<" ";
    cout<<"|                            THE NAVIGATION SYSTEM                           |"<<endl;
    for(int i = 0; i<40; i++)
        cout<<" ";
    cout<<"|                      SOURCE TO DESTINATION NAVIGATOR                       |"<<endl;
    for(int i = 0; i<40; i++)
        cout<<" ";
    cout<<"|                          PRESS ENTER TO CONTINUE...                        |"<<endl;
    for(int i = 0; i<40; i++)
        cout<<" ";
    cout<<"|                                                                            |"<<endl;
     for(int i = 0; i<40; i++)
        cout<<" ";
    cout<<"|                                                                            |"<<endl;
    for(int i = 0; i<40; i++)
        cout<<" ";
    for(int i = 0; i<39; i++)
        cout<<"-*";
    cout<<endl;
    for(int i = 0; i<312; i++)
        cout<<"*";
    getchar();
    system("cls");
    return;
}

int main()
{
    intro();
    for(int i = 0; i<312; i++)
        cout<<"*";
    cout<<endl;
    for(int i = 0; i<40; i++)
        cout<<" ";
    for(int i = 0; i<39; i++)
        cout<<"-*";
    cout<<endl;
    for(int i = 0; i<40; i++)
        cout<<" ";
    cout<<"|                                                                            |"<<endl;
    for(int i = 0; i<40; i++)
        cout<<" ";
    cout<<"|                                                                            |"<<endl;
    for(int i = 0; i<40; i++)
        cout<<" ";
    cout<<"|                         THE CITY NAVIGATION SYSTEM                         |"<<endl;
    for(int i = 0; i<40; i++)
        cout<<" ";
    cout<<"|                  FIND THE BEST ROUTE TO YOUR DESTINATION                   |"<<endl;
    for(int i = 0; i<40; i++)
        cout<<" ";
    cout<<"|                                                                            |"<<endl;
    for(int i = 0; i<40; i++)
        cout<<" ";
    cout<<"|                                                                            |"<<endl;
    for(int i = 0; i<40; i++)
        cout<<" ";
    for(int i = 0; i<39; i++)
        cout<<"-*";
    cout<<endl;
    for(int i = 0; i<312; i++)
        cout<<"*";
    cout<<endl;

    graphs();
    connection();
    mumbaidriver();
    indoredriver();
    ahmedabaddriver();

    bool b2 = true;

    while (b2)
    {
        cout<<"HERE ARE THE MAPS OF THE CITIES THAT ARE AVAILABLE IN OUR DATA BASE\n";
        string k;
        cout<<"   1. Mumbai\n";
        cout<<"   2. Indore\n";
        cout<<"   3. Ahmedabad\n";
        cout<<"Choose the city among in which you live or want to travel \n";
        cin>>k;

        if(k != "mumbai" && k != "indore" && k != "ahmedabad"&&k != "Mumbai" && k != "Indore" && k != "Ahmedabad")
        {
            cout<<"City not available in our database\n";
            cout<<"*********THANK YOU***************\n";
            return 0;
        }
        bool b1 = true;
        while(b1)
        {
            cout<<"****Here is the list of places that you can visit in  " << k << "***"<< "\n";
            int i = 1;
            for(auto it : map2[k])
            {

                cout<<"   " << i << "." << it.first << "\n";
                i++;
            }

            cout<<"\n\n";
            string src;
            cout<<"Enter your location"<< "\n";
            cin>>src;
            cout<<"\n";

            cout<<"Choose among the following options: \n";
            int ch;
            cout<<"1. Want to travel from your location to another location\n";
            cout<<"2. Want to visit all the places of city in our database\n";
            cout<<"3. Want a transport guidance at your current location\n press 1/2/3 to proceed \n";
            cin>>ch;

            switch(ch)
            {

            case 1:
            {
                string dsc;
                cout<<"Enter you destination"<<"\n";
                cin>>dsc;
                cout<<"These are the information about all the path from your location to the destination"<< "\n\n";
                printAll(map2[k][src], map2[k][dsc], map1[k], map3[k]);

                int c;
                cout<<"Do you want to see shortest path among these paths from " << src << "  to " << dsc << " type 0/1 \n\n";
                cout<<"(0 -> No & 1 -> Yes)";
                cin>>c;
                cout<<"\n";
                cout<<"********HERE IS THE SHORTEST PATH*******\n\n";
                if(c == 1)
                {
                    dijkstraalgo(map2[k][src], map2[k][dsc], map1[k], map3[k]);
                }

                cout<<"Do you want to enter stops in between your location -: " << src << " and destination :- " << dsc << " enter 0/1\n ";
                cout<<"(0 -> No & 1 -> Yes)";
                cin>>c;
                cout<<"\n";
                if(c == 1)
                {

                    unordered_map<string, int> smap;
                    cout<<"Enter number of stops that you want between source and destination"
                         << "\n\n";
                    int n;
                    cin>>n;
                    int count = 0;
                    cout<<"Now enter your stops that you want between your source and destination\n\n";

                    for(int i = 0; i < n; i++)
                    {
                        string s;
                        cin>>s;
                        smap[s] = count;
                        count++;
                    }

                    cout<<"\nHere are the paths from source to destination including stops in increasing order of distance"
                         << "\n\n";
                    vector<bool> visited(12, false);
                    string result = src + "-> ";
                    map<double, string> m1;
                    findstoppath(map2[k][src], map2[k][dsc], map1[k], n, smap, map3[k], 0, 0, visited, result, m1);
                    int w = 1;

                    for(auto it : m1)
                    {
                        cout<<"path " << w << " -: " << it.second << "   distance-: " << it.first;
                        cout<<"\n\n";
                        w++;
                    }

                    cout<<"\n";
                }
            }
            break;

            case 2:
            {
                cout<<"Here is the shortest path visiting all the places in the given city at minimum cost\n";
                Primsalgo(map2[k][src], map1[k], map3[k]);
            }
            break;

            case 3:
            {
                cout<<"          We have driver information available in our database          \n";
                cout<<"    The information about the driver in your location is as follows     \n";

                driverinfo(map2[k][src], drivermap[k]);
                cout<<"\n    Please Contact These Drivers\n";
            }
            break;
            }

            cout<<"Do you want to visit your city menu again Enter 0/1 \n";
            cout<<"(0 -> No & 1 -> Yes)";
            int t;
            cin>>t;
            if(t == 0)
                b1 = false;
        }

        cout<<"Do you want to visit some other city /Exit from our data base press 0/1 \n";
        cout<<"(0 -> No & 1 -> Yes)";
        int t1;
        cin>>t1;
        if(t1 == 0)
            b2 = false;
    }
}
