/*
MIT License

Copyright (c) 2025 Nguyễn Gia Bách

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <cstdio>
#include <Windows.h>

using namespace std;

string replaceAll(string str, const string &from, const string &to)
{
    size_t start_pos = 0;
    while ((start_pos = str.find(from, start_pos)) != string::npos)
    {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
    }
    return str;
}

string exec(const char *cmd)
{
    char buffer[128];
    string result = "";
    FILE *pipe = popen(cmd, "r");
    if (!pipe)
    {
        throw runtime_error("popen() failed!");
    }
    try
    {
        while (fgets(buffer, sizeof(buffer), pipe) != nullptr)
        {
            result += buffer;
        }
    }
    catch (...)
    {
        pclose(pipe);
        throw;
    }
    pclose(pipe);
    return result;
}

int main()
{
    string index;
    cout << "index = ? (1-23)" << "\n";
    cin >> index;

    SetConsoleOutputCP(CP_UTF8);

    vector<vector<string>> data;
    data.push_back({"Số báo danh", "Tên", "Trường",
                    "Nguyện vọng 1", "Nguyện vọng 2", "Nguyện vọng 3", "Nguyện vọng chuyên",
                    "Điểm Toán", "Điểm Văn", "Điểm ngoại ngữ", "Điểm môn chuyên",
                    "Tổng điểm chuyên", "Tổng điểm THPT", "Kết quả"});

    map<string, string> query = {
        {"name", "</td><td></td></tr><tr id=\"col_form\"style=\"font-family: 'Times New Roman', Times, serif;\"><tdstyle=\"padding: 5px 5px 5px 20px; text-align: left; color: #003366\">Họvà tên</td><td>:</td><td style=\"padding: 5px 5px 5px 5px; text-align: left\">"},
        {"gender", "</td><td></td></tr><tr id=\"col_form\"style=\"font-family: 'Times New Roman', Times, serif;\"><tdstyle=\"padding: 5px 5px 5px 20px; text-align: left; color: #003366\">Giớitính</td><td>:</td><td style=\"padding: 5px 5px 5px 5px; text-align: left\">"},
        {"school", "</td><td></td></tr><tr id=\"col_form\"style=\"font-family: 'Times New Roman', Times, serif;\"><tdstyle=\"padding: 5px 5px 5px 20px; text-align: left; color: #003366\">TrườngTH/THCS</td><td>:</td><td style=\"padding: 5px 5px 5px 5px; text-align: left\">"},
        {"district", "</td><td></td></tr><tr id=\"col_form\"style=\"font-family: 'Times New Roman', Times, serif;\"><tdstyle=\"padding: 5px 5px 5px 20px; text-align: left; color: #003366\">Quận/Huyện/TX</td><td>:</td><td style=\"padding: 5px 5px 5px 5px; text-align: left\">"},
        {"first", "</td><td></td></tr><tr id=\"col_form\"style=\"font-family: 'Times New Roman', Times, serif;\"><tdstyle=\"padding: 5px 5px 5px 20px; text-align: left; color: #003366\">Nguyệnvọng 1</td><td>:</td><td style=\"padding: 5px 5px 5px 5px; text-align: left\">"},
        {"second", "</td><td></td></tr><tr id=\"col_form\"style=\"font-family: 'Times New Roman', Times, serif;\"><tdstyle=\"padding: 5px 5px 5px 20px; text-align: left; color: #003366\">Nguyệnvọng 2</td><td>:</td><td style=\"padding: 5px 5px 5px 5px; text-align: left\">"},
        {"third", "</td><td></td></tr><tr id=\"col_form\"style=\"font-family: 'Times New Roman', Times, serif;\"><tdstyle=\"padding: 5px 5px 5px 20px; text-align: left; color: #003366\">Nguyệnvọng 3</td><td>:</td><td style=\"padding: 5px 5px 5px 5px; text-align: left\">"},
        {"major_name", "</td><td></td></tr><tr id=\"col_form\"style=\"font-family: 'Times New Roman', Times, serif;\"><tdstyle=\"padding: 5px 5px 5px 20px; text-align: left; color: #003366\">Nguyệnvọng chuyên</td><td>:</td><td style=\"padding: 5px 5px 5px 5px; text-align: left\">"},
        {"prioritize", "</td><td></td></tr><!-- <tr id=\"col_form\"style=\"font-family: 'Times New Roman', Times, serif;\"><tdstyle=\"padding: 5px 5px 5px 20px; text-align: left; color: #003366\">Điểmưu tiên</td><td>:</td><td style=\"padding: 5px 5px 5px 5px; text-align: left\">"},
        {"math", "</td><td></td></tr><tr id=\"col_form\"style=\"font-family: 'Times New Roman', Times, serif;\"><tdstyle=\"padding: 5px 5px 5px 20px; text-align: left; color: #003366\">ĐiểmToán</td><td>:</td><td style=\"padding: 5px 5px 5px 5px; text-align: left\">"},
        {"literature", "</td><td></td></tr><tr id=\"col_form\"style=\"font-family: 'Times New Roman', Times, serif;\"><tdstyle=\"padding: 5px 5px 5px 20px; text-align: left; color: #003366\">ĐiểmNgữ văn/Tiếng Việt</td><td>:</td><td style=\"padding: 5px 5px 5px 5px; text-align: left\">"},
        {"english", "</td><td></td></tr><tr id=\"col_form\"style=\"font-family: 'Times New Roman', Times, serif;\"><tdstyle=\"padding: 5px 5px 5px 20px; text-align: left; color: #003366\">ĐiểmNgoại Ngữ</td><td>:</td><td style=\"padding: 5px 5px 5px 5px; text-align: left\">"},
        {"major_point", "</td><td></td></tr><tr id=\"col_form\"style=\"font-family: 'Times New Roman', Times, serif;\"><tdstyle=\"padding: 5px 5px 5px 20px; text-align: left; color: #003366\">Điểmchuyên</td><td>:</td><td style=\"padding: 5px 5px 5px 5px; text-align: left\">"},
        {"total_1", "</td><td></td></tr><tr id=\"col_form\"style=\"font-family: 'Times New Roman', Times, serif;\"><tdstyle=\"padding: 5px 5px 5px 20px; text-align: left; color: #003366\">Tổngxét chuyên</td><td>:</td><td style=\"padding: 5px 5px 5px 5px; text-align: left\">"},
        {"total_2", "</td><td></td></tr><tr id=\"col_form\"style=\"font-family: 'Times New Roman', Times, serif;\"><tdstyle=\"padding: 5px 5px 5px 20px; text-align: left; color: #003366\">Tổngxét DTNT</td><td>:</td><td style=\"padding: 5px 5px 5px 5px; text-align: left\">"},
        {"total_3", "</td><td></td></tr><tr id=\"col_form\"style=\"font-family: 'Times New Roman', Times, serif;\"><tdstyle=\"padding: 5px 5px 5px 20px; text-align: left; color: #003366\">Tổngxét phổ thông/NTP</td><td>:</td><td style=\"padding: 5px 5px 5px 5px; text-align: left\">"},
        {"result", "</td><td></td></tr><tr id=\"col_form\"style=\"font-family: 'Times New Roman', Times, serif;\"><tdstyle=\"padding: 5px 5px 5px 20px; text-align: left; color: #003366\">Kếtquả</td><td>:</td><td style=\"padding: 5px 5px 5px 5px; text-align: left;color: #FD2323\">"},
        {"end", "</td><td></td></tr><tr id=\"col_form\"style=\"font-family: 'Times New Roman', Times, serif;\"><tdstyle=\"padding: 5px 5px 5px 20px; text-align: left; color: #003366\">Ghi chú</td><td>:</td><td style=\"padding: 5px 5px 5px 5px; text-align: left\">"}};

    int mode = 1; // 1: THPT, 3: NTP
    for (int i = 1; i <= 5000; ++i)
    {
        try
        {
            char sbd_buf[10];
            sprintf(sbd_buf, "%c%c%04d", index.size() == 2 ? index.front() : '0', index.back(), i);
            string sbd = sbd_buf;

            string curl_command = "curl \"http://103.126.153.106/tracuu/index.html?sbd=" + sbd + "&kt=" + to_string(mode) + "&timkiem=timkiem\"";
            string result = exec(curl_command.c_str());

            result = replaceAll(result, "\t", "");
            result = replaceAll(result, "\n", "");

            map<string, size_t> queryData;
            for (const auto &pair : query)
            {
                queryData[pair.first] = result.find(pair.second);
            }

            map<string, string> queryResult;

            // Extracting values based on the found positions
            // Ensure bounds checking or careful string manipulation
            queryResult["name"] = result.substr(queryData["name"] + query["name"].length(), queryData["gender"] - (queryData["name"] + query["name"].length()));
            queryResult["school"] = result.substr(queryData["school"] + query["school"].length(), queryData["district"] - (queryData["school"] + query["school"].length()));
            queryResult["first"] = result.substr(queryData["first"] + query["first"].length(), queryData["second"] - (queryData["first"] + query["first"].length()));
            queryResult["second"] = result.substr(queryData["second"] + query["second"].length(), queryData["third"] - (queryData["second"] + query["second"].length()));
            queryResult["third"] = result.substr(queryData["third"] + query["third"].length(), queryData["major_name"] - (queryData["third"] + query["third"].length()));
            queryResult["major_name"] = result.substr(queryData["major_name"] + query["major_name"].length(), queryData["prioritize"] - (queryData["major_name"] + query["major_name"].length()));
            queryResult["math"] = result.substr(queryData["math"] + query["math"].length(), queryData["literature"] - (queryData["math"] + query["math"].length()));
            queryResult["literature"] = result.substr(queryData["literature"] + query["literature"].length(), queryData["english"] - (queryData["literature"] + query["literature"].length()));
            queryResult["english"] = result.substr(queryData["english"] + query["english"].length(), queryData["major_point"] - (queryData["english"] + query["english"].length()));
            queryResult["major_point"] = result.substr(queryData["major_point"] + query["major_point"].length(), queryData["total_1"] - (queryData["major_point"] + query["major_point"].length()));
            queryResult["total_1"] = result.substr(queryData["total_1"] + query["total_1"].length(), queryData["total_2"] - (queryData["total_1"] + query["total_1"].length()));
            queryResult["total_3"] = result.substr(queryData["total_3"] + query["total_3"].length(), queryData["result"] - (queryData["total_3"] + query["total_3"].length()));
            queryResult["result"] = result.substr(queryData["result"] + query["result"].length(), queryData["end"] - (queryData["result"] + query["result"].length()));

            if (queryResult["name"] == "")
                break;

            queryResult["math"] = replaceAll(queryResult["math"], ",", ".");
            queryResult["literature"] = replaceAll(queryResult["literature"], ",", ".");
            queryResult["english"] = replaceAll(queryResult["english"], ",", ".");
            queryResult["major_point"] = replaceAll(queryResult["major_point"], ",", ".");
            queryResult["math"] = replaceAll(queryResult["math"], ",", ".");
            queryResult["literature"] = replaceAll(queryResult["literature"], ",", ".");
            queryResult["total_1"] = replaceAll(queryResult["total_1"], ",", ".");
            queryResult["total_3"] = replaceAll(queryResult["total_3"], ",", ".");

            vector<string> row;
            row.push_back(sbd);
            row.push_back(queryResult["name"]);
            row.push_back(queryResult["school"]);
            row.push_back(queryResult["first"]);
            row.push_back(queryResult["second"]);
            row.push_back(queryResult["third"]);
            row.push_back(queryResult["major_name"]);
            row.push_back(queryResult["math"]);
            row.push_back(queryResult["literature"]);
            row.push_back(queryResult["english"]);
            row.push_back(queryResult["major_point"]);
            row.push_back(queryResult["total_1"]);
            row.push_back(queryResult["total_3"]);
            row.push_back(queryResult["result"]);
            data.push_back(row);

            cout << sbd << " "
                 << queryResult["name"] << " " << queryResult["school"] << " "
                 << queryResult["first"] << " " << queryResult["second"] << " "
                 << queryResult["third"] << " " << queryResult["major_name"] << " "
                 << queryResult["math"] << " " << queryResult["literature"] << " "
                 << queryResult["english"] << " " << queryResult["major_point"] << " "
                 << queryResult["total_1"] << " " << queryResult["total_3"] << " "
                 << queryResult["result"] << endl;
        }
        catch (const exception &e)
        {
            cerr << "Some error happened: " << e.what() << endl;
            break;
        }
    }

    ofstream outputFile(index + "output.csv");
    if (outputFile.is_open())
    {
        for (const auto &row : data)
        {
            for (size_t j = 0; j < row.size(); ++j)
            {
                outputFile << row[j];
                if (j < row.size() - 1)
                {
                    outputFile << ",";
                }
            }
            outputFile << "\n";
        }
        outputFile.close();
        cout << "CSV file 'output.csv' created successfully." << endl;
    }
    else
    {
        cerr << "Unable to open file 'output.csv'" << endl;
    }

    return 0;
}