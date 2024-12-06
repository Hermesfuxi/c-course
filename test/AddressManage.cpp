#include <iostream>
#include <map>
#include <string>
#include <utility>

using namespace std;

class ContactPerson {
private:
    std::string name;
    std::string sex;
    int age{};
    std::string phone;
    std::string homeAddress;
public:
    ContactPerson() = default;

    ContactPerson(std::string name_, std::string sex_, int age_, std::string phone_, std::string homeAddress_) :
    // 发现通过移动而不是拷贝会让我们的代码性能更高。但是移动有个要求是参数必须是右值
    name(std::move(name_)), sex(std::move(sex_)), age(age_), phone(std::move(phone_)), homeAddress(std::move(homeAddress_)) {};

    void setName(std::string name_) {
        this->name = std::move(name_);
    };

    std::string getName() {
        return this->name;
    };

    void setSex(std::string sex_) {
        this->sex = std::move(sex_);
    };

    std::string getSex() {
        return this->sex;
    };

    void setAge(int age_) {
        this->age = age_;
    };

    // [[nodiscard]]属性主要功能是可以让编译器在某个函数的返回值未被使用时进行告警,当然也可以不使用,或者使用后在后面的操作中也可以忽略
    [[nodiscard]] int getAge() const {
        return this->age;
    };

    void setPhone(std::string phone_) {
        this->phone = std::move(phone_);
    };

    std::string getPhone() {
        return this->phone;
    };

    void setHomeAddress(std::string homeAddress_) {
        this->homeAddress = std::move(homeAddress_);
    };

    std::string getHomeAddress() {
        return this->homeAddress;
    };

    void toString() {
        std::cout << "联系人 " << this->name << " 信息如下：" << this->sex << ", " << this->age << "岁, 电话: "
                  << this->phone << ", 家庭住址： " << this->homeAddress << ";" << std::endl;
    };

};

class AddressManage {
private:
    std::map<std::string, ContactPerson> contactPersonMap;
public:
    /**
     * 添加新的联系人
     *
     * @param contactPersonPoint 指向要添加的联系人的指针
     *
     * 此函数首先从联系人指针中提取姓名，然后检查联系人是否已经存在于联系人映射中
     * 如果联系人已存在，则输出提示信息；如果不存在，则将联系人插入到映射中，并输出成功添加的信息
     */
    void addNewContactPerson(ContactPerson *contactPersonPoint) {
        // 通过指针从联系人对象中获取姓名
        std::string name = (*contactPersonPoint).getName();

        // 检查联系人映射中是否已有相同的姓名
        if (contactPersonMap.find(name) != contactPersonMap.end()) {
            // 如果找到相同的姓名，输出提示信息
            std::cout << "联系人已存在，请勿重复添加！" << std::endl;
        } else if(contactPersonMap.size() < 1000){
            // 如果没有找到相同的姓名，将新的联系人添加到映射中
            contactPersonMap.insert(std::pair<std::string, ContactPerson>(name, *contactPersonPoint));
            // 输出成功添加联系人的信息
            std::cout << "添加联系人成功！" << std::endl;
        } else {
            std::cout << "联系人数量已达上限，无法添加！" << std::endl;
        }
    };

    /**
     * 删除联系人
     *
     * @param name 要删除的联系人的姓名
     *
     * 此函数首先检查联系人映射中是否存在要删除的联系人，如果存在，则从映射中删除该联系人，并输出成功删除的信息
     * 如果不存在，则输出提示信息
     */
    void deleteContactPerson(const std::string& name) {
        // 检查联系人映射中是否存在要删除的联系人
        if (contactPersonMap.find(name) != contactPersonMap.end()) {
            // 如果存在，从映射中删除该联系人
            contactPersonMap.erase(name);
            // 输出成功删除联系人的信息
            std::cout << "删除联系人成功！" << std::endl;
        } else {
            // 如果不存在，输出提示信息
            std::cout << "联系人不存在，无法删除！" << std::endl;
        }
    }

    /**
     * 修改联系人信息
     *
     * @param name 要修改的联系人的姓名
     * @param newContactPerson 指向要修改的新联系人的指针
     *
     * 此函数首先检查联系人映射中是否存在要修改的联系人，如果存在，则将新的联系人信息插入到映射中，并输出成功修改的信息
     * 如果不存在，则输出提示信息
     *
     */
    void modifyContactPerson(const std::string& name, ContactPerson *newContactPerson) {
        // 检查联系人映射中是否存在要修改的联系人
        if (contactPersonMap.find(name) != contactPersonMap.end()) {
            // 如果存在，将新的联系人信息插入到映射中
            contactPersonMap.insert(std::pair<std::string, ContactPerson>(name, *newContactPerson));
            // 输出成功修改联系人的信息
            std::cout << "修改联系人信息成功！" << std::endl;
        } else {
            // 如果不存在，输出提示信息
            std::cout << "联系人不存在，无法修改！" << std::endl;
        }
    }

    /**
     * 查找联系人
     *
     * @param name 要查找的联系人的姓名
     *
     * 此函数首先检查联系人映射中是否存在要查找的联系人，如果存在，则输出该联系人的信息
     * 如果不存在，则输出提示信息
     */
    bool findContactPerson(const std::string& name) {
        // 检查联系人映射中是否存在要查找的联系人
        if (contactPersonMap.find(name) != contactPersonMap.end()) {
            // 如果存在，输出该联系人的信息
            contactPersonMap[name].toString();
            return true;
        } else {
            // 如果不存在，输出提示信息
            std::cout << "该联系人 " << name << " 不存在！" << std::endl;
            return false;
        }
    }

    ContactPerson * getContactPerson(const std::string& name) {
        // 检查联系人映射中是否存在要查找的联系人
        if (contactPersonMap.find(name) != contactPersonMap.end()) {
            // 如果存在，输出该联系人的信息
            return &(contactPersonMap[name]);
        } else {
            // 如果不存在，输出提示信息
            std::cout << "该联系人 " << name << " 不存在！" << std::endl;
            return nullptr;
        }
    }

    void showAllContactPerson() {
        // 遍历联系人映射，输出所有联系人的信息
        for (auto &contactPersonItem: contactPersonMap) {
            contactPersonItem.second.toString();
        }
    }

    // 清空联系人
    void clearContactPerson() {
        // 清空联系人映射
        contactPersonMap.clear();
        if (contactPersonMap.empty()) {
            std::cout << "通讯录已清空！" << std::endl;
        }
    }

    //  退出通讯录
    static void exitAddressManage() {
        // 退出通讯录
        exit(0);
    }
};




int main() {
    AddressManage addressManage;
    addressManage.addNewContactPerson(new ContactPerson("张三", "男", 18, "1234567890", "北京市海淀区"));
    addressManage.addNewContactPerson(new ContactPerson("李四", "女", 19, "1234567891", "北京市昌平区龙泉街"));
    addressManage.addNewContactPerson(new ContactPerson("王五", "男", 20, "1234567892", "北京市顺义区"));
    loop:
    std::cout << "==================================================" << std::endl;
    std::cout << "1.添加联系人；2.删除联系人；3.修改联系人；4.查找联系人；5.显示所有联系人；6.清空联系人；7.退出通讯录" << std::endl;
    std::cout << "请输入您的选择：";
    int choice;
    std::cin >> choice;
    switch (choice) {
        case 1:{
            auto* contactPerson = new ContactPerson();

            std::cout << "请输入要添加的联系人的姓名：";
            std::string name;
            std::cin >> name;
            contactPerson->setName(name);

            std::cout << "请输入要添加的联系人的性别：";
            std::string sex;
            std::cin >> sex;
            contactPerson->setSex(sex);

            std::cout << "请输入要添加的联系人的年龄：";
            int age;
            std::cin >> age;
            contactPerson->setAge(age);

            std::cout << "请输入要添加的联系人的电话号码：";
            std::string phoneNumber;
            std::cin >> phoneNumber;
            contactPerson->setPhone(phoneNumber);

            std::cout << "请输入要添加的联系人的地址：";
            std::string address;
            std::cin >> address;
            contactPerson->setHomeAddress(address);

            addressManage.addNewContactPerson(contactPerson);
            goto loop;
        }
        case 2:{
            std::cout << "请输入要删除的联系人的姓名：";
            std::string nameToDelete;
            std::cin >> nameToDelete;
            addressManage.deleteContactPerson(nameToDelete);
            goto loop;
        }
        case 3:{
            std::cout << "请输入要修改的联系人的姓名：";
            std::string nameToModify;
            std::cin >> nameToModify;
            bool isExist = addressManage.findContactPerson(nameToModify);

            if (isExist) {
                auto* contactPerson = addressManage.getContactPerson(nameToModify);

                std::cout << "请输入要修改的联系人的新姓名：";
                std::string newName;
                std::cin >> newName;
                contactPerson->setName(newName);

                std::cout << "请输入要修改的联系人的性别：";
                std::string sex;
                std::cin >> sex;
                contactPerson->setSex(sex);

                std::cout << "请输入要修改的联系人的年龄：";
                int age;
                std::cin >> age;
                contactPerson->setAge(age);

                std::cout << "请输入要修改的联系人的电话号码：";
                std::string phoneNumber;
                std::cin >> phoneNumber;
                contactPerson->setPhone(phoneNumber);

                std::cout << "请输入要修改的联系人的地址：";
                std::string address;
                std::cin >> address;
                contactPerson->setHomeAddress(address);

                if(newName == nameToModify){
                    addressManage.modifyContactPerson(nameToModify, contactPerson);
                } else {
                    addressManage.addNewContactPerson(contactPerson);
                    addressManage.deleteContactPerson(nameToModify);
                }
            } else {
                std::cout << "联系人不存在，请返回，并在‘1.添加联系人’中进行操作";
            }


            goto loop;
        }
        case 4:{
            std::cout << "请输入要查找的联系人的姓名：";
            std::string nameToFind;
            std::cin >> nameToFind;
            addressManage.findContactPerson(nameToFind);
            goto loop;
        }
        case 5:{
            addressManage.showAllContactPerson();
            goto loop;
        }
        case 6:{
            addressManage.clearContactPerson();
            goto loop;
        }
        case 7:{
            AddressManage::exitAddressManage();
        }
        default:{
            std::cout << "输入有误，请重新输入！" << std::endl;
            goto loop;
        }
    }

//    addressManage.showAllContactPerson();
//    addressManage.findContactPerson("张三");
//    addressManage.findContactPerson("唐三");
//    addressManage.modifyContactPerson("张三", new ContactPerson("张三", "男", 18, "1234567890", "北京市昌平龙泉街"));
//    addressManage.findContactPerson("张三");
//    addressManage.deleteContactPerson("王五");
//    addressManage.showAllContactPerson();
//    addressManage.clearContactPerson();
//    addressManage.showAllContactPerson();
//    AddressManage::exitAddressManage();
    return 0;
}