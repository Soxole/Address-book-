#include "contactsmodel.h"
#include <QQmlEngine>
#include <QDebug>



ContactsModel::ContactsModel()
{
    const bool updateResult = updateContacts();
    if(!updateResult){ qWarning() << "Update contacts failed.";}
}

bool ContactsModel::updateContacts() {
//    bool requestResult = false;
//    std::vector<Contact> contactsResult;
//    std::tie(requestResult, contactsResult) = m_contactsReader.requestContactsBrowse();
    auto&&[requestResult, contactsResult] = m_contactsReader.requestContactsBrowse();
    if(requestResult){
        m_contacts.swap(contactsResult);
        emit dataChanged(createIndex(0, 0), createIndex(static_cast<int>(m_contacts.size()), 0));
    }
    return requestResult;
}

QHash<int, QByteArray> ContactsModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[ContactRoles::NameRole] = "name";
    roles[ContactRoles::SurnameRole] = "surname";
    roles[ContactRoles::PhoneNumberRole] = "phoneNumber";

//    for(int i = 0; i < roles.size(); ++i)
//        qDebug() << (roles.begin() + i).key() << " " << (roles.begin() + i).value();

    return roles;
}

int ContactsModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent); //cast to void; name is not used in the body of a function
    return static_cast<int>(m_contacts.size());
}

QVariant ContactsModel::data(const QModelIndex &index, int role) const //role - name, surname and phone
{
    if(!index.isValid() || index.row() > rowCount(index)) return {}; //check index; UB
    const Contact &contact {m_contacts.at(index.row())};

    switch (role) {
    case ContactRoles::NameRole: {
        return QVariant::fromValue(contact.firstName());
    }
    case ContactRoles::SurnameRole: {
        return QVariant::fromValue(contact.surname());
    }
    case ContactRoles::PhoneNumberRole: {
        return QVariant::fromValue(contact.phone());
    }
    default:{
        return true;
    }
    }
}

//register type
void ContactsModel::registerMe(const std::string &moduleName)
{
    qmlRegisterType<ContactsModel>(moduleName.c_str(), 1, 0, "ContactsModel");
}
