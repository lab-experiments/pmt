//
//  CommandModel.h
//  pmt-project
//
//  Created in october, 2015 by Thaisa Mirely
//

#ifndef pmt_project_CommandModel_h
#define pmt_project_CommandModel_h

#include <string.h>
#include <vector>
#include <sstream>
#include <iostream>

class CommandModel {

private:
    
    int m_emax;
    std::string m_pattern;
    std::vector<std::string> m_text_file_names;
    
public:
    
    CommandModel() : m_emax(0) {}
    
    int GetEmax()
    {
        return this->m_emax;
    }
    
    std::string GetPattern()
    {
        return this->m_pattern;
    }
    
    std::vector<std::string> GetTextFileNames()
    {
        return this->m_text_file_names;
    }
    
    void SetEmax(int value)
    {
        this->m_emax = value;
    }
    
    void SetPattern(std::string value)
    {
        this->m_pattern = value;
    }
    
    void SetTextFilenames(std::vector<std::string> value)
    {
        this->m_text_file_names = value;
    }

};

#endif
