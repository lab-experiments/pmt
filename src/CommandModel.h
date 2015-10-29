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
    std::vector<std::string> m_textFilenames;
    
public:
    
    CommandModel() : m_emax(0) {}
    
    int getEmax()
    {
        return this->m_emax;
    }
    
    std::string getPattern()
    {
        return this->m_pattern;
    }
    
    std::vector<std::string> getTextFilenames()
    {
        return this->m_textFilenames;
    }
    
    void setEmax(int value)
    {
        this->m_emax = value;
    }
    
    void setPattern(std::string value)
    {
        this->m_pattern = value;
    }
    
    void setTextFilenames(std::vector<std::string> value)
    {
        this->m_textFilenames = value;
    }

};

#endif
