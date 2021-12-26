#include "includes/contactsreader.h"

namespace {
    const std::vector<Contact> mockData{
        {"Wylie", "Johns", "380618395414"}
    };
}



std::pair<bool, std::vector<Contact> > ContactsReader::requestContactsBrowse()
{
    return std::make_pair(true, mockData);
}
