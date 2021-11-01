#pragma once
#include <QString>

class Contact
{
private:
    QString m_firstName;
    QString m_surname;
    QString m_phone;

public:
    Contact() = default;
    Contact(QString firstName, QString surname, QString phone);

    //geters
    const QString &phone() const;
    const QString &firstName() const;
    const QString &surname() const;
};


