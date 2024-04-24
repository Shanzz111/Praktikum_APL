#include <iostream>
#include <string>
#include <cctype>

using namespace std;
// Nama Pasien
// Nomor rekam medis / identitas yang dapat digunakan
// Alamat lengkap pasien tinggal sdh
// Data kelahiran pasien (tanggal, bulan, tahun, dan kota) sdh
// Jenis gender pasien sdh
// Kontak keluarga terdekat pasien
// string nama_pasien[1000] = {"Muhammad azam", "Raihan fitri", "Vicky Ahmad"},alamat_pasien[1000] = {"Kutai Barat", "Samarinda Sebrang", "Samarinda"},
// tanggal_lahir[1000] = {"21 Mei 2005", "12 Oktober 2004", "29 Februari 2005"},gender_pasien[1000] = {"Laki-Laki", "Laki-Laki", "Laki-Laki"}, tempat_lahir[1000] = {"Kutai Barat", "Samarinda Sebrang", "Samarinda"};
// string gender;
// string choose;
// int nomor_medis_pasien[1000] = {1,2,3},kontak_keluarga[1000] = {234234,45345,235462},

int ukuran = 3;
string gender, choose;

struct kelahiran{ //Nested Struct
    string tanggal_lahir;
    string tempat_lahir;
};

struct pasien{
    string nama_pasien;
    int nomor_medis_pasien;
    string alamat_pasien;
    kelahiran kelahiran_pasien;// Nested struct
    string gender_pasien;
    string kontak_keluarga;
};

pasien data_pasien[1000] = { // Array of struct
    {"Muhammad Shandy", 1, "Kutai Barat", "Kutai Barat","21 Mei 2005","Laki-Laki", "081253342720"},
    {"Raihan fitri", 2 , "Samarinda Sebrang", "Samarinda Sebrang", "12 Oktober 2004", "Laki-Laki", "081263637474" },
    {"Vicky Ahmad", 3, "Samarinda", "Samarinda","29 Februari 2005","Laki-Laki", "081253536464" }
};

pasien data_pasien_sebelum_diurutkan[1000];

void tampilkanDataPasien(pasien *ptr_pasien) {
    cout << "Nama Pasien : " << ptr_pasien->nama_pasien << endl;
    cout << "Nomor Pasien : " << ptr_pasien->nomor_medis_pasien << endl;
    cout << "Alamat Pasien : " << ptr_pasien->alamat_pasien << endl;
    cout << "Tempat Lahir Pasien : " << ptr_pasien->kelahiran_pasien.tempat_lahir << endl;
    cout << "Tanggal Lahir Pasien : " << ptr_pasien->kelahiran_pasien.tanggal_lahir << endl;
    cout << "Gender Pasien : " << ptr_pasien->gender_pasien << endl;
    cout << "Kontak Keluarga Pasien : " << ptr_pasien->kontak_keluarga << endl;
    cout << endl;

}

void tampil(pasien *ptr_data_pasien, int ukuran) {
    for(int i = 0; i < ukuran; i++) {
        tampilkanDataPasien(&ptr_data_pasien[i]);
    }
    system("pause");
}

void salinDataPasien(pasien *ptr_data_pasien, pasien *ptr_data_pasien_sebelum_diurutkan, int ukuran) {
    for(int i = 0; i < ukuran; i++) {
        ptr_data_pasien_sebelum_diurutkan[i] = ptr_data_pasien[i];
    }
}

int inputInteger(string pesan) {
    int num;
    string input;

    while (true) {
        cout << pesan;
        cin >> input;

        try {
            num = stoi(input);
            break;
        } catch (const invalid_argument& e) {
            cout << "Jangan memasukan nilai selain integer!!!.\n";
        }
    }
    return num;
}

string inputString(string pesan, bool releaseBuff) {
    string hasil;

    if(releaseBuff) {
        fflush(stdin);
    }

    do {
        cout << pesan;
        getline(cin, hasil);

        if(hasil == "") {
            cout << "Input tidak boleh kosong!!!\n";
        } else if(hasil == " "){
            cout << "Input tidak boleh kosong!!!\n";
        }
    } while(hasil == "" || hasil == " ");

    return hasil;
}

string jenis_kelamin(){
    x:
    cout << "Gender Pasien [ L/W ] : ";
    cin >> gender;
    if(gender == "L" || gender == "l"){
        return "Laki - Laki";
    } else if(gender == "W" || gender == "w"){
        return "Wanita";
    } else {
        cout << "Anda Salah Input" << endl;
        goto x;
    }
}

bool login(){
    string nama,nim;
    
    nama  = inputString("NAMA : ", true);
    nim   = inputString("NIM  : ", false);

    if((nama == "Shandy" ) && (nim == "2309106106")){
        return true;
    } else{
        return false;
    }

}

void tambah(){ //Rekursif
    data_pasien[ukuran].nama_pasien                    = inputString("Nama Pasien : ",               true);
    data_pasien[ukuran].nomor_medis_pasien             = inputInteger("Nomor Rekam Medis Pasien : ");
    data_pasien[ukuran].alamat_pasien                  = inputString("Alamat Pasien : ",             true);
    data_pasien[ukuran].kelahiran_pasien.tempat_lahir  = inputString("Tempat Lahir Pasien : ", false);
    data_pasien[ukuran].kelahiran_pasien.tanggal_lahir = inputString("Tanggal Lahir Pasien :",       false);
    data_pasien[ukuran].gender_pasien                  = jenis_kelamin();
    data_pasien[ukuran].kontak_keluarga                = inputString("Kontak Keluarga Pasien : ", true);
    ukuran++;
    p:
    cout << "Apakah ingin menambahkan data pasien lagi [ Y/N ] ? ";
    cin >> choose;
    if (choose == "Y" || choose == "y") {
        tambah();
    } else if (choose == "n" || choose == "N") {
    } else {
        cout << "Anda Salah Input" << endl;
        goto p;
    }
}

void insertionSortDescendingNama(pasien arr[], int n) {
    for (int i = 1; i < n; i++) {
        pasien key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].nama_pasien < key.nama_pasien) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void selectionSortAscendingNomorMedis(pasien arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j].nomor_medis_pasien < arr[min_idx].nomor_medis_pasien) {
                min_idx = j;
            }
        }
        swap(arr[min_idx], arr[i]);
    }
}
void selectionSortDescendingNomorMedis(pasien arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int max_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j].nomor_medis_pasien > arr[max_idx].nomor_medis_pasien) {
                max_idx = j;
            }
        }
        swap(arr[max_idx], arr[i]);
    }
}


void bubbleSortAscendingGender(pasien arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].gender_pasien > arr[j + 1].gender_pasien) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void menu_sort(){
    salinDataPasien(data_pasien,data_pasien_sebelum_diurutkan,ukuran);
    system("cls");
    menu:
    cout << "=============================================================" << endl;
    cout << "::                       PILIHAN                           ::" << endl;
    cout << "=============================================================" << endl;
    cout << ":: [ 1 ] TAMPILKAN DATA PASIEN ( TIDAK DIURUTKAN )         ::" << endl;
    cout << ":: [ 2 ] TAMPILKAN DATA PASIEN ( SORT NAMA DSC )           ::" << endl;
    cout << ":: [ 3 ] TAMPILKAN DATA PASIEN ( SORT NOMOR MEDIS ASC )    ::" << endl;
    cout << ":: [ 4 ] TAMPILKAN DATA PASIEN ( SORT GENDER ASC )         ::" << endl;
    cout << ":: [ 5 ] KEMBALI                                           ::" << endl;
    cout << "======================================================+=======" << endl;
    enum opsi{TAMPIL = 1, INSERTION, SELECTION, BUBBLE, KELUAR};
    int pilih = inputInteger("PILIH : ");
    switch(pilih){
        case TAMPIL:
            tampil(data_pasien_sebelum_diurutkan,ukuran);
            system("cls");
            goto menu;
            break;
        case INSERTION:
            insertionSortDescendingNama(data_pasien,ukuran);
            tampil(data_pasien,ukuran);
            system("cls");
            goto menu;
            break;
        case SELECTION:
            selectionSortAscendingNomorMedis(data_pasien,ukuran);
            tampil(data_pasien,ukuran);
            system("cls");
            goto menu;
            break;
        case BUBBLE:
            bubbleSortAscendingGender(data_pasien, ukuran);
            tampil(data_pasien,ukuran);
            system("cls");
            goto menu;
            break;
        case KELUAR:
            break;
        default:
            cout << "Anda Salah Input" << endl;
            system("pause");
            goto menu;
    }
}

void binarySearchAscendingNomorMedis(pasien arr[], int n){
    selectionSortAscendingNomorMedis(arr,n);
    int key; cout << "NOMOR MEDIS PASIEN : ";cin >> key;
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid].nomor_medis_pasien == key) {
            cout << "Nomor Medis " << key << " ditemukan pada indeks: " << mid << endl;
            return;
        }
        if (arr[mid].nomor_medis_pasien < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << "Tidak ditemukan" << endl;
}

void interpolationSearchDescendingNomorMedis(pasien arr[], int n) {
    selectionSortDescendingNomorMedis(arr, n); 
    int key;
    cout << "NOMOR MEDIS PASIEN : ";
    cin >> key;

    int low = 0, high = n - 1;
    while (low <= high && key <= arr[low].nomor_medis_pasien && key >= arr[high].nomor_medis_pasien) {
        if (low == high) {
            if (arr[low].nomor_medis_pasien == key) {
                cout << "Nomor Medis " << key << " ditemukan pada indeks: " << low << endl;
                return;
            } else {
                break;
            }
        }

        // Interpolasi rumus untuk memperkirakan lokasi kunci
        int pos = low + (((double)(high - low) / (arr[low].nomor_medis_pasien - arr[high].nomor_medis_pasien)) * (arr[low].nomor_medis_pasien - key));

        if (arr[pos].nomor_medis_pasien == key) {
            cout << "Nomor Medis " << key << " ditemukan pada indeks: " << pos << endl;
            return;
        } else if (arr[pos].nomor_medis_pasien < key) {
            low = pos + 1;
        } else {
            high = pos - 1;
        }
    }
    cout << "Tidak ditemukan" << endl;
}

void menu_search(){
    system("cls");
    menu:
    cout << "=============================================================" << endl;
    cout << "::                       PILIHAN                           ::" << endl;
    cout << "=============================================================" << endl;
    cout << ":: [ 1 ] CARI NOMOR MEDIS PASIEN ( BINARY & ASC )          ::" << endl;
    cout << ":: [ 2 ] CARI NOMOR MEDIS PASIEN ( INTERPOLATION & DSC)    ::" << endl;
    cout << ":: [ 3 ] KEMBALI                                           ::" << endl;
    cout << "=============================================================" << endl;
    enum opsi{CARI_ASC = 1, CARI_DSC, KELUAR};
    int pilih = inputInteger("PILIH : ");
    switch(pilih){
        case CARI_ASC:
            binarySearchAscendingNomorMedis(data_pasien,ukuran);
            system("pause");
            system("cls");
            goto menu;
            break;
        case CARI_DSC:
            interpolationSearchDescendingNomorMedis(data_pasien,ukuran);
            system("pause");
            system("cls");
            goto menu;
            break;
        case KELUAR:
            break;
        default:
            cout << "Anda Salah Input" << endl;
            system("pause");
            goto menu;
        }
}

void ubah(){ //Prosedur
    int cari = inputInteger("Nomor Pasien : ");
    for(int i = 0; i < ukuran; i++){
        if(cari == data_pasien[i].nomor_medis_pasien){
            data_pasien[i].nama_pasien                    = inputString("Nama Pasien : ", true);
            data_pasien[i].nomor_medis_pasien             = inputInteger("Nomor Rekam Medis Pasien : ");
            data_pasien[i].alamat_pasien                  = inputString("Alamat Pasien : ", true);
            data_pasien[i].kelahiran_pasien.tempat_lahir  = inputString("Tempat Lahir Pasien : ", false);
            data_pasien[i].kelahiran_pasien.tanggal_lahir = inputString("Tanggal Lahir Pasien :", false);
            data_pasien[i].gender_pasien                  = jenis_kelamin();
            data_pasien[i].kontak_keluarga                = inputString("Kontak Keluarga Pas1ien : ", true);
            break;
        }
    }
}

void hapus(){//Prosedur
    int hapus = inputInteger("Nomor Pasien : ");
    for(int i = 0; i < ukuran; i++){
        if(hapus == data_pasien[i].nomor_medis_pasien){
            for(int j = i; j < ukuran; j++){
                data_pasien[j].nama_pasien                     = data_pasien[j+1].nama_pasien;
                data_pasien[j].nomor_medis_pasien              = data_pasien[j+1].nomor_medis_pasien;
                data_pasien[j].alamat_pasien                   = data_pasien[j+1].alamat_pasien;
                data_pasien[j].kelahiran_pasien.tempat_lahir   = data_pasien[j+1].kelahiran_pasien.tempat_lahir;
                data_pasien[j].kelahiran_pasien.tanggal_lahir  = data_pasien[j+1].kelahiran_pasien.tanggal_lahir;
                data_pasien[j].gender_pasien                   = data_pasien[j+1].gender_pasien;
                data_pasien[j].kontak_keluarga                 = data_pasien[j+1].kontak_keluarga;
            }
            ukuran -= 1;
        }
    }
}

int main(){
    while(1){
        system("cls");
        cout << "=======================" << endl;
        cout << "::   HALAMAN LOGIN   ::" << endl;
        cout << "=======================" << endl;
        cout << ":: [ 1 ] LOGIN       ::" << endl;
        cout << ":: [ 2 ] KELUAR      ::" << endl;
        cout << "=======================" << endl;

        int tanya = inputInteger("PILIH : ");
        if(tanya == 1){
            for(int i = 0 ; i <= 3 ; i++){
                if(i == 3){
                    exit(1);
                }
                system("cls");
                cout << "=======================" << endl;
                cout << "::   HALAMAN LOGIN   ::" << endl;
                cout << "=======================" << endl;
                if(login()){
                    system("cls");
                    menu:
                    cout << "=============================================================" << endl;
                    cout << "::                       MENU USER                         ::" << endl;
                    cout << "=============================================================" << endl;
                    cout << ":: [ 1 ] MASUKKAN DATA PASIEN                              ::" << endl;
                    cout << ":: [ 2 ] TAMPILKAN DATA PASIEN                             ::" << endl;
                    cout << ":: [ 3 ] UBAH DATA PASIEN                                  ::" << endl;
                    cout << ":: [ 4 ] HAPUS DATA PASIEN                                 ::" << endl;
                    cout << ":: [ 5 ] CARI NOMOR MEDIS PASIEN                           ::" << endl;
                    cout << ":: [ 6 ] KELUAR                                             ::" << endl;
                    cout << "=============================================================" << endl;
                    enum opsi{CREATE = 1, READ, UPDATE, DELETE, SEARCH, KELUAR};

                    int pilih = inputInteger("PILIH : ");
                    switch(pilih){
                        case CREATE:
                            tambah();
                            system("cls");
                            goto menu;
                            break;
                        case READ:
                            menu_sort();
                            system("cls");
                            goto menu;
                            break;
                        case UPDATE:
                            ubah();
                            system("cls");
                            goto menu;
                            break;
                        case DELETE:
                            hapus();
                            system("cls");
                            goto menu;
                            break;
                        case SEARCH:
                            menu_search();
                            system("cls");
                            goto menu;
                            break;
                        case KELUAR:
                            break;
                            system("cls");
                        default:
                            cout << "Anda Salah Input" << endl;
                            system("pause");
                            goto menu;
                    }
                }else{
                    cout << "Anda Salah Input" << endl;
                    system("pause");
                    continue;
                }
                break;
            }
        } else if (tanya == 2){
            exit(1);
            system("cls");
        } else {
            cout << "Anda Salah Input" << endl;
            system("pause");
            system("cls");
        }
    }
    return 0;
}