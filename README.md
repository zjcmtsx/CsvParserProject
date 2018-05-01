# CsvParserProject
csv配置表 解析器， 通过keyName读取

### 规定
表头有三行：
1. 第一行： 汉字描述，可以随意
2. 第二行： 字段名称（代码中通过这个名字来取列值）
3. 第三行： 字段类型（给配表人看的，代码中不用）

每行可以通过列名keyName来获取列的值，这样在修改csv表结构的时候，不需要去关注列的下标，只需知道列名就行了。

### 使用方式

```
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
```




