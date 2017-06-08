//经典解法，赋值运算符函数
CMyString& CMyString::operator = (const CMyString &str)
{
	//容错测试
	if(this == &str){
		return *this;
	}
	delete []m_pData;
	m_pData = nullptr;
	m_pData = new char[strlen(str.m_pData)+1];
	strcpy(m_pData, str.m_pData);
	return *this;
}
