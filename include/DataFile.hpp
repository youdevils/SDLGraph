#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include "../include/Point.hpp"

class DataFile
{
private:
public:
    void Read_Data_From_File(std::vector<std::shared_ptr<Point>> &array);
    void Write_Data_To_File(std::vector<std::shared_ptr<Point>> &array);
    DataFile(/* args */);
    ~DataFile();
};

void DataFile::Read_Data_From_File(std::vector<std::shared_ptr<Point>> &array)
{
    std::ifstream in("point_data.txt");

    float x = 0.0f;
    float y = 0.0f;
    // in >> x >> y;
    while (in.good() && !in.eof())
    {
        in >> x >> y;
        std::shared_ptr<Point> point = std::make_shared<Point>("f", x, y);
        array.push_back(point);
    }

    in.close();
}

void DataFile::Write_Data_To_File(std::vector<std::shared_ptr<Point>> &array)
{
    std::ofstream out("point_data.txt");
    for (auto point : array)
    {
        out << point->GetX() << " " << point->GetY() << "\n";
    }
    out.close();
}

DataFile::DataFile(/* args */)
{
}

DataFile::~DataFile()
{
}
