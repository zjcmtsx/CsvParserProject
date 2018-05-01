
#include "CSVFile.h"
#include "TestConfig.h"

int main( int argc, char* argv[] )
{
	CSVFile csv;
	if(csv.loadFile("item.csv"))
	{
		// 读取方式1 
		std::cout << "读取方式2" << std::endl;
		int rowCount = csv.GetRowCount();
		for (int i = 0; i < rowCount; i++)
		{
			int ID = csv.GetRowInt(i, "ID");
			string Type = csv.GetRowString(i, "Type");
			string Name = csv.GetRowString(i, "Name");
			int Function = csv.GetRowInt(i, "Function");
			double Xpos = csv.GetRowDouble(i, "Xpos");
			double Ypos = csv.GetRowDouble(i, "Ypos");
			double Zpos = csv.GetRowDouble(i, "Zpos");
			printf("ID=%d, Type=%s, Name=%s, Function=%d, Xpos=%lf, Ypos=%lf, Zpos=%lf\n",
				ID, Type.c_str(), Name.c_str(), Function, Xpos, Ypos, Zpos);

		}

		// 读取方式2
		std::cout << "读取方式2" << std::endl;
		for (int i = 0; i < rowCount; i++)
		{
			CSVRow* rowData_ptr = csv.GetRow(i);
			if (rowData_ptr)
			{
				TestConfig cfg;
				cfg.FromCsvRow(rowData_ptr);
			}
		}
	}
    return 0;
}