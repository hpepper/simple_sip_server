#ifndef JSON_LOGGING
#define JSON_LOGGING

#include <string>


/**
 * @brief Json logging helper class
 *
 * A singleton for printing app output in json format for getting picked up by container logging solution
 */
class JsonLogging {
public:
    JsonLogging();
    ~JsonLogging();
    void logText(std::string sLogLevel, std::string sText, std::string sFilename, int fileLineNumber);
    std::string convertErrnoToErrString(int errnum);

private:
    std::string m_appName;
};

#endif // JSON_LOGGING
