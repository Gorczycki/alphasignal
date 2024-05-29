#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <limits>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <unordered_map>
#include <memory>
#include <variant>
#include <optional>
#include <tuple>
#include <format>


// Alphavantage API:

// curl 'https://www.alphavantage.co/query?function=TIME_SERIES_DAILY&symbol=COP&apikey=O0WO3FXT6S62ZZEG&datatype=csv' -o Conocodata2.csv
// curl 'https://www.alphavantage.co/query?function=TIME_SERIES_DAILY&symbol=CVX&apikey=O0WO3FXT6S62ZZEG&datatype=csv' -o Chevrondata2.csv
// curl 'https://www.alphavantage.co/query?function=TIME_SERIES_DAILY&symbol=TTE&apikey=O0WO3FXT6S62ZZEG&datatype=csv' -o Totalenergiesdata2.csv
// curl 'https://www.alphavantage.co/query?function=TIME_SERIES_DAILY&symbol=XOM&apikey=O0WO3FXT6S62ZZEG&datatype=csv' -o Exxondata2.csv
// curl 'https://www.alphavantage.co/query?function=TIME_SERIES_DAILY&symbol=SHEL&apikey=O0WO3FXT6S62ZZEG&datatype=csv' -o Shelldata2.csv


// Create volume function to take note when daily volume may veer to a low or high
// Create price function to do the same, as well as make adjusted mean and variance for each moving 30 day calendar

// Chevron
// Totalenergies
// Exxon
// Shell
// Conoco-Phillips


std::map<std::vector<int>, std::vector<long>> Conoco(std::fstream &fin);
std::map<std::vector<int>, std::vector<long>> Chevron(std::fstream &fin);  
std::map<std::vector<int>, std::vector<long>> Totalenergies(std::fstream &fin);  
std::map<std::vector<int>, std::vector<long>> Exxon(std::fstream &fin);  
std::map<std::vector<int>, std::vector<long>> Shell(std::fstream &fin);   

std::vector<int> Volspike(std::vector<std::map<std::vector<int>, std::vector<long>>> Alldatavector);

int main()
{
    std::fstream fin;
    fin.open("Conocodata2.csv", std::ios::in);
    if(!fin.is_open())
    {
        std::cerr<<"Error opening file"<<std::endl;
        return 1;
    }
    std::map<std::vector<int>, std::vector<long>> ConocodataMap = Conoco(fin);
    fin.close();

    //

    fin.open("Chevrondata2.csv", std::ios::in);
    if(!fin.is_open())
    {
        std::cerr<<"Error opening file"<<std::endl;
        return 1;
    }
    std::map<std::vector<int>, std::vector<long>> ChevrondataMap = Chevron(fin);
    fin.close();

    //

    fin.open("Totalenergiesdata2.csv", std::ios::in);
    if(!fin.is_open())
    {
        std::cerr<<"Error opening file"<<std::endl;
        return 1;
    }
    std::map<std::vector<int>, std::vector<long>> TotalenergiesdataMap = Totalenergies(fin);
    fin.close();

    //

    fin.open("Exxondata2.csv", std::ios::in);
    if(!fin.is_open())
    {
        std::cerr<<"Error opening file"<<std::endl;
        return 1;
    }
    std::map<std::vector<int>, std::vector<long>> ExxondataMap = Exxon(fin);
    fin.close();

    //

    fin.open("Shelldata2.csv", std::ios::in);
    if(!fin.is_open())
    {
        std::cerr<<"Error opening file"<<std::endl;
        return 1;
    }
    std::map<std::vector<int>, std::vector<long>> ShelldataMap = Shell(fin);
    fin.close();



    // All data points into one vector:
    // it's a vector of the respective maps
    std::vector<std::map<std::vector<int>, std::vector<long>>> Alldatavector; 
    Alldatavector.push_back(ConocodataMap);
    Alldatavector.push_back(ChevrondataMap);
    Alldatavector.push_back(TotalenergiesdataMap);
    Alldatavector.push_back(ExxondataMap);
    Alldatavector.push_back(ShelldataMap);
    std::vector<int> Volumehits = Volspike(Alldatavector);
    for(int i = 0; i<Volumehits.size(); i++)
        std::cout<<Volumehits[i]<<std::endl;
    


    //all dates
    /*
    for(const auto& entry : dataMap)
    {
        const auto& date = entry.first;
        const auto& values = entry.second;

        for(const auto& part : date)
        {
            std::cout<< part << "-";
        }
        std::cout<<": ";

        for (const auto& value : values) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
    */



   //specific date
   /*
   std::vector<int> specificDate = {2024,5,13};
   const auto &values = ChevrondataMap[specificDate];
   for(const auto &value : values)
   {
       std::cout<<value<< " ";
   }
   */
   



    
    
    
    









    
    









    return 0;
}



std::vector<int> Volspike(std::vector<std::map<std::vector<int>, std::vector<long>>> Alldatavector)
{
    for(int i = 0; i<Alldatavector.size(); i++)
    {
        std::map<std::vector<int>, std::vector<long>> Currentcompany = Alldatavector[i];

        for(const auto& entry : Currentcompany)
        {
        const auto& date = entry.first;
        const auto& values = entry.second;

        for(const auto& part : date)
        {
            std::cout<< part << "-";
        }
        std::cout<<": ";

        for (const auto& value : values) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
        }
    }  






    return ...;
}








std::map<std::vector<int>, std::vector<long>> Conoco(std::fstream &fin)
{
    //function to convert fstream read-in to map,
    //key is date vector, data is vector of prices and last slot of vector is volume(#5).

    std::map<std::vector<int>, std::vector<long>> collection;

    std::vector<std::vector<std::string>> data;
    std::string line, word;

    if(std::getline(fin, line))
    {
        //...
    }

    while(std::getline(fin, line))
    {
        std::stringstream ss(line);
        std::vector<std::string> row;
        while(std::getline(ss, word, ','))
        {
            row.push_back(word);
        }
        data.push_back(row);
    }

    for(const auto& row : data)
    {
        if(row.size() == 6)
        {
            std::vector<int> date;
            std::stringstream dateStream(row[0]);
            std::string datePart;
            while(std::getline(dateStream, datePart, '-'))
            {
                date.push_back(std::stoi(datePart));
            }

            std::vector<long> values;
            for(long i = 1; i<row.size(); ++i)
            {
                values.push_back(static_cast<long>(std::stof(row[i])));
            } 

            collection[date] = values;
        }
    }


    return collection;
}


std::map<std::vector<int>, std::vector<long>> Chevron(std::fstream &fin)
{
    //function to convert fstream read-in to map,
    //key is date vector, data is vector of prices and last slot of vector is volume(#5).

    std::map<std::vector<int>, std::vector<long>> collection;

    std::vector<std::vector<std::string>> data;
    std::string line, word;

    if(std::getline(fin, line))
    {
        //...
    }

    while(std::getline(fin, line))
    {
        std::stringstream ss(line);
        std::vector<std::string> row;
        while(std::getline(ss, word, ','))
        {
            row.push_back(word);
        }
        data.push_back(row);
    }

    for(const auto& row : data)
    {
        if(row.size() == 6)
        {
            std::vector<int> date;
            std::stringstream dateStream(row[0]);
            std::string datePart;
            while(std::getline(dateStream, datePart, '-'))
            {
                date.push_back(std::stoi(datePart));
            }

            std::vector<long> values;
            for(long i = 1; i<row.size(); ++i)
            {
                values.push_back(static_cast<long>(std::stof(row[i])));
            } 

            collection[date] = values;
        }
    }


    return collection;
}


std::map<std::vector<int>, std::vector<long>> Totalenergies(std::fstream &fin)
{
    //function to convert fstream read-in to map,
    //key is date vector, data is vector of prices and last slot of vector is volume(#5).

    std::map<std::vector<int>, std::vector<long>> collection;

    std::vector<std::vector<std::string>> data;
    std::string line, word;

    if(std::getline(fin, line))
    {
        //...
    }

    while(std::getline(fin, line))
    {
        std::stringstream ss(line);
        std::vector<std::string> row;
        while(std::getline(ss, word, ','))
        {
            row.push_back(word);
        }
        data.push_back(row);
    }

    for(const auto& row : data)
    {
        if(row.size() == 6)
        {
            std::vector<int> date;
            std::stringstream dateStream(row[0]);
            std::string datePart;
            while(std::getline(dateStream, datePart, '-'))
            {
                date.push_back(std::stoi(datePart));
            }

            std::vector<long> values;
            for(long i = 1; i<row.size(); ++i)
            {
                values.push_back(static_cast<long>(std::stof(row[i])));
            } 

            collection[date] = values;
        }
    }


    return collection;
}


std::map<std::vector<int>, std::vector<long>> Exxon(std::fstream &fin)
{
    //function to convert fstream read-in to map,
    //key is date vector, data is vector of prices and last slot of vector is volume(#5).

    std::map<std::vector<int>, std::vector<long>> collection;

    std::vector<std::vector<std::string>> data;
    std::string line, word;

    if(std::getline(fin, line))
    {
        //...
    }

    while(std::getline(fin, line))
    {
        std::stringstream ss(line);
        std::vector<std::string> row;
        while(std::getline(ss, word, ','))
        {
            row.push_back(word);
        }
        data.push_back(row);
    }

    for(const auto& row : data)
    {
        if(row.size() == 6)
        {
            std::vector<int> date;
            std::stringstream dateStream(row[0]);
            std::string datePart;
            while(std::getline(dateStream, datePart, '-'))
            {
                date.push_back(std::stoi(datePart));
            }

            std::vector<long> values;
            for(long i = 1; i<row.size(); ++i)
            {
                values.push_back(static_cast<long>(std::stof(row[i])));
            } 

            collection[date] = values;
        }
    }


    return collection;
}


std::map<std::vector<int>, std::vector<long>> Shell(std::fstream &fin)
{
    //function to convert fstream read-in to map,
    //key is date vector, data is vector of prices and last slot of vector is volume(#5).

    std::map<std::vector<int>, std::vector<long>> collection;

    std::vector<std::vector<std::string>> data;
    std::string line, word;

    if(std::getline(fin, line))
    {
        //...
    }

    while(std::getline(fin, line))
    {
        std::stringstream ss(line);
        std::vector<std::string> row;
        while(std::getline(ss, word, ','))
        {
            row.push_back(word);
        }
        data.push_back(row);
    }

    for(const auto& row : data)
    {
        if(row.size() == 6)
        {
            std::vector<int> date;
            std::stringstream dateStream(row[0]);
            std::string datePart;
            while(std::getline(dateStream, datePart, '-'))
            {
                date.push_back(std::stoi(datePart));
            }

            std::vector<long> values;
            for(long i = 1; i<row.size(); ++i)
            {
                values.push_back(static_cast<long>(std::stof(row[i])));
            } 

            collection[date] = values;
        }
    }


    return collection;
}
