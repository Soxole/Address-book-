#include "includes/contact.h"

Contact::Contact(QString firstName, QString surname, QString phone)
    : m_firstName(std::move(firstName)),
      m_surname(std::move(surname)),
      m_phone(std::move(phone))
{

}

const QString &Contact::firstName() const
{
    return m_firstName;
}

const QString &Contact::surname() const
{
    return m_surname;
}

const QString &Contact::phone() const
{
    return m_phone;
}




