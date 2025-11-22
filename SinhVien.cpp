#include <iostream>
#include <string>
using namespace std;

struct SinhVien {
    string MSSV;
    string hoTen;
    int NamSinh;
    float GPA;
};

struct Node {
    SinhVien data;
    Node* next;
};

struct List {
    Node* head;
};

void initList(List &l) { // khoi tao danh sach rong
    l.head = NULL;
}


Node* createNode(SinhVien sv) { // tao node moi
    Node* p = new Node;
    p->data = sv;
    p->next = NULL;
    return p;
}

void addFirst(List &l, SinhVien sv) { // them vao dau danh sach
    Node* newNode = createNode(sv);
    newNode->next = l.head;
    l.head = newNode;
}

void printList(List l) { // in danh sach
    Node* p = l.head;
    if (p == NULL) {
        cout << "Danh sach rong!\n";
        return;
    }

    cout << "\n--- DANH SACH SINH VIEN ---\n";
    while (p != NULL) {
        cout << "Ho ten : " << p->data.hoTen << endl;
        cout << "MSSV   : " << p->data.MSSV << endl;
        cout << "Nam sinh: " << p->data.NamSinh << endl;
        cout << "GPA    : " << p->data.GPA << endl;
        cout << "---------------------------\n";
        p = p->next;
    }
}

int listLength(List l) { // dem so luong sinh vien
    Node* p = l.head;
    int count = 0;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    return count;
}

int countGPA32(List l) { // dem sinh vien GPA > 3.2
    Node* p = l.head;
    int count = 0;
    while (p != NULL) {
        if (p->data.GPA > 3.2)
            count++;
        p = p->next;
    }
    return count;
}

void sortByGPA(List &l) { // sap xep tang dan theo GPA
    if (l.head == NULL) return;

    for (Node* p = l.head; p != NULL; p = p->next) {
        for (Node* q = p->next; q != NULL; q = q->next) {
            if (p->data.GPA > q->data.GPA) {
                swap(p->data, q->data);
            }
        }
    }
}

void insertSorted(List &l, SinhVien sv) { // chen sinh vien vao danh sach da sap xep
    Node* newNode = createNode(sv);

    if (l.head == NULL || sv.GPA <= l.head->data.GPA) {
        newNode->next = l.head;
        l.head = newNode;
        return;
    }

    Node* p = l.head;
    while (p->next != NULL && p->next->data.GPA < sv.GPA) {
        p = p->next;
    }

    newNode->next = p->next;
    p->next = newNode;
}

int main() {
    List DSSV;
    initList(DSSV);


    SinhVien a = {"20233513", "Vu Dinh Luc", 2005, 3.6};
    SinhVien b = {"20244444", "Nguyen Vu Phuon Linh", 2006, 3.6};
    SinhVien c = {"20235555", "Hoang Nguyen Thanh Tung", 2005, 1.8};

    addFirst(DSSV, a);
    addFirst(DSSV, b);
    addFirst(DSSV, c);

    cout << "\nDanh sach ban dau:\n";
    printList(DSSV);

    cout << "\nChieu dai danh sach: " << listLength(DSSV) << endl;
    cout << "So SV GPA > 3.2: " << countGPA32(DSSV) << endl;

    sortByGPA(DSSV);
    cout << "\nDanh sach sau khi sap xep tang dan theo GPA:\n";
    printList(DSSV);

    // Thêm sinh viên GPA = 2.4
    SinhVien newSV = {"SV04", "Hoang Cuu Bao", 2005, 2.4};
    insertSorted(DSSV, newSV);
    cout << "\nDanh sach sau khi chen sinh vien GPA = 2.4:\n";
    printList(DSSV);

    return 0;
}