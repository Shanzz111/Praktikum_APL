#include <iostream>

using namespace std;

void dari_celcius(){
    float celcius,reamur,fahrenheit,kelvin;
    cout << "CELCIUS : ";
    cin >> celcius;
    while(true){
        system("cls");
        cout << "=======================" << endl;
        cout << "::   KONVERSI SUHU   ::" << endl;
        cout << "=======================" << endl;
        cout << ":: [ 1 ] REAMUR      ::" << endl;
        cout << ":: [ 2 ] FAHRENHEIT  ::" << endl;
        cout << ":: [ 3 ] KELVIN      ::" << endl;
        cout << ":: [ 4 ] KEMBALI     ::" << endl;
        cout << "=======================" << endl;

        int suhu_akhir;
        cout << "KONVERSI SUHU KE : ";
        cin >> suhu_akhir;

        if(suhu_akhir == 1){
            reamur = (4.0/5.0)*celcius;
            cout << "REAMUR : " << reamur << endl;
            system("pause");
            break;
        }else if(suhu_akhir == 2){
            fahrenheit = 9.0/5.0*celcius + 32;
            cout << "FAHRENHEIT : " << fahrenheit << endl;
            system("pause");
            break;

        }else if(suhu_akhir == 3){
            kelvin = celcius + 273;
            cout << "KELVIN : " << kelvin << endl;
            system("pause");
            break;

        }else if(suhu_akhir == 4){
            break;
        }else {
            cout << "Tolong Input dalam Rentang 1 - 4" << endl;
            system("pause");
            continue;
        }
    }
}
void dari_reamur(){
    float celcius,reamur,fahrenheit,kelvin;
    cout << "REAMUR : ";
    cin >> reamur;
    while(true){
        
        system("cls");
        cout << "=======================" << endl;
        cout << "::   KONVERSI SUHU   ::" << endl;
        cout << "=======================" << endl;
        cout << ":: [ 1 ] CELCIUS     ::" << endl;
        cout << ":: [ 2 ] FAHRENHEIT  ::" << endl;
        cout << ":: [ 3 ] KELVIN      ::" << endl;
        cout << ":: [ 4 ] KEMBALI     ::" << endl;
        cout << "=======================" << endl;
        int suhu_akhir;
        cout << "KONVERSI SUHU KE : ";
        cin >> suhu_akhir;

        if(suhu_akhir == 1){
            celcius = (5.0/4.0)*reamur;
            cout << "CELCIUS : " << celcius << endl;
            system("pause");
            break;

        }else if(suhu_akhir == 2){
            fahrenheit = 9.0/4.0*reamur + 32;
            cout << "FAHRENHEIT : " << fahrenheit << endl;
            system("pause");
            break;

        }else if(suhu_akhir == 3){
            kelvin = 5.0/4.0*reamur + 273;
            cout << "KELVIN : " << kelvin << endl;
            system("pause");
            break;

        }else if(suhu_akhir == 4){
            break;
        }else {
            cout << "Tolong Input dalam Rentang 1 - 4" << endl;
            system("pause");
            continue;
        }
    }

}
void dari_fahrenheit(){
    float celcius,reamur,fahrenheit,kelvin;
    cout << "FAHRENHEIT : ";
    cin >> fahrenheit;
    while(true){
        system("cls");
        cout << "=======================" << endl;
        cout << "::   KONVERSI SUHU   ::" << endl;
        cout << "=======================" << endl;
        cout << ":: [ 1 ] CELCIUS     ::" << endl;
        cout << ":: [ 2 ] REAMUR      ::" << endl;
        cout << ":: [ 3 ] KELVIN      ::" << endl;
        cout << ":: [ 4 ] KEMBALI     ::" << endl;
        cout << "=======================" << endl;
        int suhu_akhir;
        cout << "KONVERSI SUHU KE : ";
        cin >> suhu_akhir;

        if(suhu_akhir == 1){
            celcius = (5.0/9.0)*(fahrenheit - 32);
            cout << "CELCIUS : " << celcius << endl;
            system("pause");
            break;

        }else if(suhu_akhir == 2){
            reamur = 4.0/9.0*(fahrenheit - 32);
            cout << "REAMUR : " << reamur << endl;
            system("pause");
            break;

        }else if(suhu_akhir == 3){
            kelvin = (5.0/9.0)*(fahrenheit - 32) + 273;
            cout << "KELVIN : " << kelvin << endl;
            system("pause");
            break;

        }else if(suhu_akhir == 4){
            break;
        }else {
            cout << "Tolong Input dalam Rentang 1 - 4" << endl;
            system("pause");
            continue;
        }
    }    
}
void dari_kelvin(){
    float celcius,reamur,fahrenheit,kelvin;
    cout << "KELVIN : ";
    cin >> kelvin;
    while(true){
        system("cls");
        cout << "=======================" << endl;
        cout << "::   KONVERSI SUHU   ::" << endl;
        cout << "=======================" << endl;
        cout << ":: [ 1 ] CELCIUS     ::" << endl;
        cout << ":: [ 2 ] REAMUR      ::" << endl;
        cout << ":: [ 3 ] FAHRENHEIT  ::" << endl;
        cout << ":: [ 4 ] KEMBALI     ::" << endl;
        cout << "=======================" << endl;
        int suhu_akhir;
        cout << "KONVERSI SUHU KE : ";
        cin >> suhu_akhir;
        if(suhu_akhir == 1){
            celcius = kelvin - 273;
            cout << "CELCIUS : " << celcius << endl;
            system("pause");
            break;

        }else if(suhu_akhir == 2){
            reamur = 4.0/5.0*(kelvin-273);
            cout << "REAMUR : " << reamur << endl;
            system("pause");
            break;

        }else if(suhu_akhir == 3){
            fahrenheit = 9.0/5.0*(kelvin-273) + 32;
            cout << "FAHRENHEIT : " << fahrenheit << endl;
            system("pause");
            break;

        }else if(suhu_akhir == 4){
            break;
        }else {
            cout << "Tolong Input dalam Rentang 1 - 4" << endl;
            system("pause");
            continue;
        }
    }
    
}
void user(){
    menu:
    system("cls");
    cout << "=======================" << endl;
    cout << "::   KONVERSI SUHU   ::" << endl;
    cout << "=======================" << endl;
    cout << ":: [ 1 ] CELCIUS     ::" << endl;
    cout << ":: [ 2 ] REAMUR      ::" << endl;
    cout << ":: [ 3 ] FAHRENHEIT  ::" << endl;
    cout << ":: [ 4 ] KELVIN      ::" << endl;
    cout << ":: [ 5 ] KEMBALI     ::" << endl;
    cout << "=======================" << endl;

    enum suhu{CELCIUS = 1, REAMUR, FAHRENHEIT, KELVIN, KELUAR};

    int suhu_awal;
    cout << "SUHU YANG INGIN DIKONVERSI : ";
    cin >> suhu_awal;

    switch(suhu_awal){
        case CELCIUS:
            dari_celcius();
            system("cls");
            goto menu;
            break;
        case REAMUR:
            dari_reamur();
            system("cls");
            goto menu;
            break;
        case FAHRENHEIT:
            dari_fahrenheit();
            system("cls");
            goto menu;
            break;
        case KELVIN:
            dari_kelvin();
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

}
void login_sampai_user(){
    while(true){
        system("cls");
        cout << "=======================" << endl;
        cout << "::   HALAMAN LOGIN   ::" << endl;
        cout << "=======================" << endl;
        cout << ":: [ 1 ] LOGIN       ::" << endl;
        cout << ":: [ 2 ] KELUAR      ::" << endl;
        cout << "=======================" << endl;

        int tanya;
        cout << "PILIH : ";
        cin >> tanya;
        if(tanya == 1){
            for(int i = 0 ; i <= 3 ; i++){
                if(i == 3){
                    exit(1);
                }
                system("cls");
                cout << "=======================" << endl;
                cout << "::   HALAMAN LOGIN   ::" << endl;
                cout << "=======================" << endl;
                string nama,nim;
                cout << "NAMA : ";
                cin >> nama;
                cout << "NIM  : ";
                cin >> nim;
                if((nama == "Shandy" ) && (nim == "2309106106")){
                    user();
                } else{
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
}
int main(){
    login_sampai_user();
    return 0;
}