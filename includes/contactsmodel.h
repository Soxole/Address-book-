#pragma once
#include <QAbstractListModel>
#include <QHash>
#include <vector>
#include "contact.h"
#include "contactsreader.h"

class ContactsModel : public QAbstractListModel
{
    Q_OBJECT
private:
    std::vector<Contact> m_contacts;
    ContactsReader m_contactsReader;
    enum ContactRoles {
        NameRole = Qt::UserRole + 1,  //257
        SurnameRole,
        PhoneNumberRole
    };

    bool updateContacts();

public:
    ContactsModel();
    static void registerMe(const std::string &moduleName);  //register a type in qml as class

    QHash<int, QByteArray> roleNames() const override;
    int rowCount(const QModelIndex &parent = {}) const override;
    QVariant data(const QModelIndex &index = {}, int role = Qt::DisplayRole) const override;
};

