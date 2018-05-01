#pragma once
#include <string>
#include "CSVRow.h"


/*
	²âÊÔÅäÖÃÎÄ¼þ
*/
class TestConfig
{
public:
    TestConfig()
    {
        Clear();
    }
	
	void FromCsvRow(CSVRow* row_ptr)
	{
		ID			= row_ptr->GetRowInt("ID");
		Type		= row_ptr->GetRowString("Type");
		Name		= row_ptr->GetRowString("Name");
		Function	= row_ptr->GetRowInt("Function");
		Xpos		= row_ptr->GetRowDouble("Xpos");
		Ypos		= row_ptr->GetRowDouble("Ypos");
		Zpos		= row_ptr->GetRowDouble("Zpos");
		
		printf("ID=%d, Type=%s, Name=%s, Function=%d, Xpos=%lf, Ypos=%lf, Zpos=%lf\n",
				ID, Type.c_str(), Name.c_str(), Function, Xpos, Ypos, Zpos);
	}

private:
	
    void Clear()
    {
        ID = 0;
        Type = "";
		Name = "";
        Function = 0;
        Xpos = 0;
        Ypos = 0;
        Zpos = 0;
    }

private:
    unsigned int ID;
    string Type;
	std::string Name;
    unsigned int Function;
    double Xpos;
    double Ypos;
    double Zpos;

};
