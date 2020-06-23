#include <iostream>
using namespace std;


struct karyawan
{
    string nik, nama;
    char golongan; int jamKerja, jamLembur, gaji;
};

void output(struct karyawan data[100], int jumlah); //Fungsi untuk menampilkan seluruh data yang telah tersimpan
void urut(struct karyawan data[100], struct karyawan temp, int x, int y); // Fungsi untuk mengurutkan Data
void listData(struct karyawan data[100], int jumlah); // Fungsi Menampilkan Data lebih dari 1
void garis()
{
    cout << "============================================================================================\n";
}
void CV()
{
    garis();
    garis();
    cout << "\t\t\t\tData Penggajian Karyawan CV.ABC\n";
    garis();
} 
void tabel()
{
    CV();
    cout << "NIK\t\tNama\t\tGolongan\tJam Kerja\tJam Lembur\tTotal Gaji\n";
    garis();
}

int main ()
{
    
    int jumlah, x, y, pil, ketemu = 0;
    string nik, nama; char  golongan,yt;
    karyawan data[100];
    karyawan temp;
    system("cls");
    CV();
    cout << "Masukkan Jumlah Karyawan   : "; cin >> jumlah;

    for(x=0; x<jumlah; x++) // Menginput Data Karyawan
    {   
        garis();
        cout << "\nKaryawan ke - "<< x+1;
        cout << "\nMasukkan NIK       : ";        cin >> data[x].nik;
        cout << "Masukkan Nama      : ";        cin >> data[x].nama;
        golongan :
        cout << "Masukkan Golongan  : ";    cin >> data[x].golongan;
        cout << "Masukkan Jam Kerja : ";    cin >> data[x].jamKerja;

            if(data[x].jamKerja > 40) // Menghitung Jam Lembur karyawan
            {
                data[x].jamLembur = data[x].jamKerja - 40;
                data[x].jamKerja  = data[x].jamKerja - data[x].jamLembur;
            }
            else
            {
                data[x].jamLembur = 0;
            } 
        
        switch (data[x].golongan) // Menghitung Gaji Karyawan sesuai Golongan
        {
            case '1'  :
                data[x].gaji = 3000 * data[x].jamKerja + (data[x].jamLembur * (1.5 * 3000));
                break;
            case '2'  :
                data[x].gaji = 3500 * data[x].jamKerja + (data[x].jamLembur * (1.5 * 3500));
                break;
            case '3'  :
                data[x].gaji = 4000 * data[x].jamKerja + (data[x].jamLembur * (1.5 * 4000));
                break;
            case '4'  :
                data[x].gaji = 5000 * data[x].jamKerja + (data[x].jamLembur * (1.5 * 5000));
                break;
            default :
                data[x].golongan = NULL;
                cout << "Golongan Tidak Terdaftar !\nCoba Input Golongan dengan Benar!\n";
                goto golongan;
                break;
        } // end switch gaji karyawan
        garis();
    }

    tabel();
    listData(data, x);
    garis();
        tampilanPilihan :
    cout << "Pilihan mencari Data Karyawan  : " // Memberikan Opsi pencarian Data
         << "\n1.Urutan Gaji Tertinggi\n2.Urutan Gaji Terendah\n3.Sesuai Kategori\nPilihan Anda    : "; cin >> pil;

         switch (pil)
         {
             case 1 :
                cout << "\nMenampilkan data dari gaji Tertinggi\n";
                for(x=0; x<jumlah; x++)
                 {
                    for(y=x+1; y<jumlah; y++)
                    if(data[x].gaji < data[y].gaji)
                    {
                        urut(data, temp, x, y);
                    }
                 }
                cout << "Pencarian Data : \n";
                tabel();
                listData(data, x);
                garis();
                break;
             case 2 :
                cout << "\nMenampilkan data dari gaji Terendah\n";
                for(x=0; x<jumlah; x++)
                 {
                    for(y=x+1; y<jumlah; y++)
                    if(data[x].gaji > data[y].gaji)
                    {
                        urut(data, temp, x, y);
                    }
                 }
                cout << "Pencarian Data : \n";
                tabel();
                listData(data, x);
                garis();
                 break;
             case 3 :
                    kategoriPilihan :
                cout << "\nKategori yang Tersedia : "
                     << "\n1.NIK\n2.Nama\n3.Golongan\nPilihan Anda  : "; cin >> pil;
                     

                     switch (pil)
                     {
                        case 1  :
                        
                            cout << "\nMasukkan NIK : "; cin >> nik;
                            tabel();
                            for(x=0; x<jumlah; x++)
                            {
                                if(nik == data[x].nik)
                                {
                                ketemu = 1;
                                output(data, x);
                                }
                            }
                            garis();
                            if(ketemu == 0)
                                {   cout << "Mohon Maaf!\nNIK    : " << nik
                                     << "\nTidak terdaftar disistem!\n";
                                }
                            break;
                        case 2  :
                            cout << "\nMasukkan Nama : "; cin >> nama;
                            tabel();
                            for(x=0; x<jumlah; x++)
                            {
                                if(nama == data[x].nama)
                                {
                                ketemu = 1;
                                output(data, x);
                                }
                            }
                            garis();
                            if(ketemu == 0)
                                {   cout << "Mohon Maaf!\nNama    : " << nama
                                     << "\nTidak terdaftar disistem!\n";
                                }
                            break;
                        case 3  :
                            cout << "\nMasukkan Golongan : "; cin >> golongan;
                            tabel();
                            for(x=0; x<jumlah; x++)
                            {
                                if(golongan == data[x].golongan)
                                {
                                ketemu = 1;
                                output(data, x);
                                }
                            }
                            garis();
                            if(ketemu == 0)
                                {   cout << "Mohon Maaf!\nGolongan    : " << golongan
                                     << "\nTidak terdaftar disistem!\n";
                                }
                            break;
                            
                        default :
                            ketemu = 0;
                            system("cls");
                            cout << "Piihan tidak dikenali. Mohon Masukkan Pilihan yang Tersedia\n";
                            goto kategoriPilihan;
                            break;    
                     }
                break;
             default :
                system("cls");
                cout << "Piihan tidak dikenali. Mohon Masukkan Pilihan yang Tersedia\n";
                goto tampilanPilihan;
                break;
         }

    akhir :
        cout << "\n\nApakah Ingin Mencari data karyawan lagi (Y/N) : "; cin >> yt;
        if(yt == 'Y' || yt == 'y')
        {
            goto tampilanPilihan;
        }
        else
        {
            system("cls");
            CV();
            cout << "\t\t\tTerima Kasih telah menggunakan Program Ini.\n";
            garis();
        }
        
    return 0;
}


void listData(struct karyawan data[100], int jumlah)
{
    for(int x=0; x<jumlah; x++)
    {
        output(data, x);
    }
}

void output(struct karyawan data[100], int x)
{
    cout << data[x].nik << "\t\t" << data[x].nama << "\t\t" << data[x].golongan << "\t\t"
    << data[x].jamKerja << "\t\t" << data[x].jamLembur << "\t\tRp." << data[x].gaji << endl; 
}

void urut(struct karyawan data[100], struct karyawan temp, int x, int y)
{
    temp.nik    = data[x].nik; 
    data[x].nik = data[y].nik;
    data[y].nik = temp.nik;
                                                        temp.nama       = data[x].nama;
                                                        data[x].nama    = data[y].nama;
                                                        data[y].nama    = temp.nama;
    temp.golongan       = data[x].golongan;
    data[x].golongan    = data[y].golongan;
    data[y].golongan    = temp.golongan;
                                                        temp.jamKerja   = data[x].jamKerja;
                                                        data[x].jamKerja= data[y].jamKerja;
                                                        data[y].jamKerja= temp.jamKerja;
    temp.jamLembur      = data[x].jamLembur;
    data[x].jamLembur   = data[y].jamLembur;
    data[x].jamLembur   = temp.jamLembur;
                                                        temp.gaji       = data[x].gaji;
                                                        data[x].gaji    = data[y].gaji;
                                                        data[y].gaji    = temp.gaji;

}