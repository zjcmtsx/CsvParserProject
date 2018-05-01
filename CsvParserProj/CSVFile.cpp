#include "CSVFile.h"
#include "CSVRow.h"
//#include <direct.h>  

CSVFile::CSVFile()
{
    m_rowsVec.clear();
	m_keyNameIndexMap.clear();
}

CSVFile::~CSVFile()
{
	for (CSVRowVector::iterator itr = m_rowsVec.begin(); itr != m_rowsVec.end(); ++itr)
	{
		CSVRow* row_ptr = *itr;
		if (row_ptr)
		{
			delete row_ptr;
			*itr = nullptr;
		}
	}
	m_rowsVec.clear();
}

bool CSVFile::loadFile(const char* szFileName)
{
	
	/*
	char buff[1000];  
    _getcwd(buff, 1000);  
    std::cout << "��ǰ·���ǣ�"<<buff<<"\n";  
    getchar();  
	*/

	//ifstream inFile("D:\\WorkPlace\\csvParser\\CsvParserProj\\CsvParserProj\\Debug\\item.csv");
	ifstream inFile(szFileName);
    if (!inFile)
    {
        return false;
    }

	// ��ȡÿһ�е����ݣ� ���Ұ�ÿ�е����ݸ��ݶ��ŷָ��string�� �����stringVector��
	string strLineContext;
    while (getline(inFile, strLineContext))
    {
        // ��ָ���ָ�����ȡÿ����Ϣ�б�
        StringVector vecValue;
        Split(strLineContext, vecValue);
		CSVRow* row_ptr = new CSVRow(this, vecValue);
        m_rowsVec.push_back(row_ptr);
    }

	// �������Ҫ���У���һ���������ڶ�������keyName���������ֶ����ͣ�
	if (m_rowsVec.size() < KEY_TYPE_ROW_NUM)
	{
		return false;
	}

	// ����keyName��index��ӳ��
	CSVRow* keyNameRow_ptr = m_rowsVec[NAME_ROW_INDEX];
	const StringVector& keyNameVec = keyNameRow_ptr->GetRowValueVec();
	for (int index = 0; index < (int)keyNameVec.size(); index++)
	{
		m_keyNameIndexMap[keyNameVec[index]] = index;
	}
    return true;
}



bool CSVFile::Split( const string& strLine, StringVector& vecString )
{
    int nBegin = 0;
    int nEnd = 0;
	char splitChar = ',';
    while ((nEnd = strLine.find_first_of(splitChar, nBegin)) != string::npos)
    {
        vecString.push_back(strLine.substr(nBegin, nEnd - nBegin));
        nBegin = nEnd + 1;
    }

    if ((nBegin = strLine.find_last_of(splitChar, strLine.length() - 1)) != string::npos)
    {
        vecString.push_back(strLine.substr(nBegin + 1, strLine.length() - 1));
    }

    return true;
}

int CSVFile::KeyNameToIndex(const string& keyName)
{
	StringIntMap::iterator finder = m_keyNameIndexMap.find(keyName);
	if(finder != m_keyNameIndexMap.end())
	{
		return m_keyNameIndexMap[keyName];
	}
	return -1;
}

string CSVFile::GetFieldValue(const int& row, const string& keyName)
{
	int index = KeyNameToIndex(keyName);
	if(index >= 0)
	{
		// ���ݴӵ����п�ʼ��
		CSVRow* rowData_ptr = GetRow(row);
		if(rowData_ptr)
		{
			return rowData_ptr->GetValueString(index);
		}
	}
	return "";
}


CSVRow* CSVFile::GetRow(const int& row)
{
	if (row >= 0 && row < GetRowCount() )
	{
		return m_rowsVec[KEY_TYPE_ROW_NUM + row];
	}
	return nullptr;
}

int CSVFile::GetRowCount()
{
	return (int)m_rowsVec.size() - KEY_TYPE_ROW_NUM;
}


int CSVFile::GetRowInt(const int& row, const string& keyName)
{
	string valueStr = GetFieldValue(row, keyName);
	return atoi(valueStr.c_str());
}

double CSVFile::GetRowDouble(const int& row, const string& keyName)
{
	string valueStr = GetFieldValue(row, keyName);
	return atof(valueStr.c_str());
}

string CSVFile::GetRowString(const int& row, const string& keyName)
{
	return GetFieldValue(row, keyName);
}

long long CSVFile::GetRowLongLong(const int& row, const string& keyName)
{
	string valueStr = GetFieldValue(row, keyName);
	return atoll(valueStr.c_str());
}