#include "json_logging.h"

#include <cerrno>
#include <cstring>


// TODO make this a singleton
JsonLogging::JsonLogging()
{
    m_appName = "sipgate";
}

JsonLogging::~JsonLogging()
{

}

/**
 * 
 * TODO escape any " in the string vars
 */
void JsonLogging::logText(std::string sLogLevel, std::string sText, std::string sFilename, int fileLineNumber)
{
    printf("{");
    printf(" \"%s.level\": \"%s\"", m_appName.c_str(), sLogLevel.c_str());
    printf(", \"%s.text\": \"%s\"", m_appName.c_str(), sText.c_str());
    printf(", \"%s.filename\": \"%s\"", m_appName.c_str(), sFilename.c_str());
    printf(", \"%s.line\": \"%d\"", m_appName.c_str(), fileLineNumber);
    printf("}");
    printf("\n");
}


std::string JsonLogging::convertErrnoToErrString(int errnum)
{
    return(std::strerror(errnum));
}