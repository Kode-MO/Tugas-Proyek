#include <iostream>
using namespace std;

struct mahasiswa // struktur Data Mahasiswa
{
    string nim, grade;
    int uts, uas, kuis, proyek, kehadiran, hasil;
};

void output (struct mahasiswa data[100], int jumlah);
void tabel (struct mahasiswa data[100], int jumlah);
void urut (struct mahasiswa data[100], struct mahasiswa temp, int x, int y);

void garis()
{
    cout << "======================================================================================\n";
}

void list()
{
    garis();
    cout << "No\tNIM\t\tUAS\tUAN\tKuis\tProyek\tKehadiran\tTotal\tGrade\n";
    garis();
}

int main ()
{
    system ("cls");
 int x, y, jumlah, pil, ketemu = 0;
 char yn;
 string mhs;
 string grade;
    mahasiswa data[100];
    mahasiswa temp;

    garis();
    garis();
    cout << "\t\tNama\t\t: Muhid Mustari"
    << "\n\t\tKampus\t\t: Universitas Muslim Indonesia"
    << "\n\t\tFakultas\t: Fakultas Ilmu Komputer (FIKOM)"
    << "\n\t\tProgram\t\t: Data Nilai Akhir Mahasiswa\n";
    garis();
    garis();
    
    cout << "\nMasukkan Jumlah Mahasiswa  : "; cin >> jumlah; // Menginput Jumlah Mahasiswa yang diinginkan

    
    for(x=0; x<jumlah; x++) //Menginput Data Nilai Mahasiswa
    {
        cout << "Mahasiswa ke " << x + 1;
        cout << "\nNIM        : "; cin >> data[x].nim;
        cout << "UTS        : "; cin >> data[x].uts; 
        cout << "UAS        : "; cin >> data[x].uas; 
        cout << "KUIS       : "; cin >> data[x].kuis; 
        cout << "Proyek     : "; cin >> data[x].proyek; 
        cout << "Kehadiran  : "; cin >> data[x].kehadiran; 

    /* Total Kehadiran mahasiswa maksimal 14 kali pertemuan
        jadi perhitungan untuk mendapatkan Nilai 100 atau mendekati
        saya menggunakan point 7.14 untuk dikalikan dengan jumlah kehadiran mahasiswa
        dan dikonversi menjadi Nilai Kehadiran Para Mahasiswa */
        data[x].kehadiran = 7.14 * data[x].kehadiran;

    /* data Hasil adalah Data nilai Keseluruhan Mahasiswa yang menentukan Nilai Akhir
        Rincian hitungannya untuk masing-masing Nilai memiliki persentasi % sendiri
        yang ditentukan Oleh Dosen atau Kontrak Kuliah sendiri*/ 
        data[x].hasil = (data[x].uts * 0.2) + (data[x].uas * 0.25) + (data[x].kuis * 0.2)
                        + (data[x].proyek * 0.2) + (data[x].kehadiran * 0.15) ;
                
    // Proses Ini akan Mengkonversi Nilai Akhir menjadi IPK/Grade Mahasiswa dengan perhitungan nilai seperti dibawah
        if(data[x].hasil > 85){
            data[x].grade = "A" ;
        } else if(data[x].hasil >= 81){
            data[x].grade = "A-";
        } else if(data[x].hasil >= 76){
            data[x].grade = "B+";
        } else if(data[x].hasil >= 71){
            data[x].grade = "B";
        } else if(data[x].hasil >= 66){
            data[x].grade = "B-";
        } else if(data[x].hasil >= 61){
            data[x].grade = "C+";
        } else if(data[x].hasil >= 51){
            data[x].grade = "C";
        } else if(data[x].hasil >= 45){
            data[x].grade = "D";
        } else if(data[x].hasil < 45){
            data[x].grade = "E";
        }
        
        cout << endl;
    }

    awal :  // Akan Memulai disini ketika Proses pemanggilan instruksi digunakan
      	
    tabel(data, x); /* Ketika Proses Nilai sudah ditemukan di atas
       				 fungsi ini akan menyimpan Data Mahasiswa dan menampilkan dalam bentuk Tabel*/ 
	
	opsi : 	// Akan Memulai disini ketika Proses pemanggilan instruksi digunakan

       cout << "\nPilihan Tampilan : "  // Ini Pilihan untuk Menampilkan Data Mahasiswa 
    << "\n1. Menampilkan Data Mahasiswa dari Nilai Tertinggi"
    << "\n2. Menampilkan Data Mahasiswa dari Nilai Terendah"
    << "\n3. Menampilkan Data Mahasiswa sesuai Kategori"
    << "\nPilihan Anda : "; cin >> pil;

    switch(pil)
    {
        case 1 : //untuk Tampilan Dari Nilai Tertinggi
                for(x=0; x<jumlah; x++)
                {
                    for(y=x+1; y<jumlah; y++)
                    if(data[x].hasil < data[y].hasil)
                    {
                        urut(data, temp, x, y); // disinilah Fungsi urut sangat berguna karna saya tidak perlu mengetikan lagi datanya
                    }
                }

                cout << "Pencarian Data : \n";
                tabel(data, x);
                goto lanjut;
                break;

        case 2 :  //untuk Tampilan Dari Nilai Terendah
                for(x=0; x<jumlah; x++)
                {
                    for(y=x+1; y<jumlah; y++)
                    if(data[x].hasil > data[y].hasil)
                    {
                        urut(data, temp, x, y); // disinilah Fungsi urut sangat berguna karna saya tidak perlu mengetikan lagi datanya
                    }
                }

                cout << "Pencarian Data : \n";
                tabel(data, x);
                goto lanjut;
                break;

        case 3 : // Untuk Menampilkan Menurut Kategori yang ada dipilihan
                ulang :
                cout << "\nKategori :"
                << "\n1.NIM\n2.Nilai Akhir\n3.Grade"
                <<"\nPilihan Anda : "; cin >> pil;

                if(pil == 1) // Mencari Data sesuai NIM
                {			               
                            cout << "Masukkan NIM : "; cin >> mhs;
                            for(x=0; x<jumlah; x++)
                            {
                                if(mhs==data[x].nim) // Jika NIM yang diketik sama NIM pada data Mahasiswa akan melakukan program didalam selection
                                {   
									ketemu = 1;                 
                                    list();
                                    output(data, x);
                                    garis();
                                }
                            }

                            if(ketemu == 0) // Jika tidak ada NIM yang sama akan melakukan proses ini
                            {
                                cout << "Data tidak Ditemukan\n";
                                /* Ini adalah Lompatan statement */
                                goto lanjut;
                            }
                            goto lanjut;
                                                       
                }
                else if(pil == 2) /* Mencari data menggunakan data Nilai Akhir Mahasiswa dan langsung saya tampilkan 3 mode yaitu Nilai yang dicari
                                    melalui proses yang bernilai sama, ascending dan descending*/
                {
                            int hasil;
                            cout << "Masukkan Nilai akhir Mahasiswa : "; cin >> hasil;
                            
                            cout << "Pencarian : "
                            << "\n1. Mencari Data Mahasiswa yang memiliki Nilai Akhir : == " << hasil << "\n";
                            list(); ketemu = 0;
                            for(x=0; x<jumlah; x++)
                            {      
                                if(hasil == data[x].hasil)
                                {           
                                    ketemu = 1;                        
                                    output(data, x);
                                    garis();
                                }
                            }
            
                            if(ketemu == 0)
                            {
                                cout << "Data tidak Ditemukan";
                            }

                            cout << "\n\n2. Mencari Data Mahasiswa yang memiliki Nilai Akhir : >= " << hasil << "\n";

                            ketemu = 0;
                            list();
                            for(x=0; x<jumlah; x++)
                            {
                                if(hasil <= data[x].hasil)
                                {   
                                    ketemu = 1;                                                                  
                                    output(data, x);                                    
                                }
                            }
                            
                            if(ketemu == 0)
                            {
                                cout << "Data tidak Ditemukan\n";
                            }
                            
							garis();
                            cout << "\n\n3. Mencari Data Mahasiswa yang memiliki Nilai Akhir : <= " << hasil << "\n";

                            ketemu = 0;
                            list();
                            for(x=0; x<jumlah; x++)
                            {
                                if(hasil >= data[x].hasil)
                                {       
                                    ketemu = 1;                                                                
                                    output(data, x);
                                }
                            }
                            
                            if(ketemu == 0)
                            {
                                cout << "Data tidak Ditemukan\n";
                            }
                            garis();
                            goto lanjut;
                }
                else if(pil == 3) // Proses Mencari Data Mahasiswa sesuai GRADE yang diinginkan
                {
                 cout << "Masukkan Grade : "; cin >> grade;

							ketemu = 0;
							list();
                            for(x=0; x<jumlah; x++)
                            {
                                if(grade==data[x].grade)
                                {   
									ketemu = 1;                       
                                    output(data, x);                                    
                                }
                            }
                            garis();
                            if(ketemu = 0)
                            {
                                cout << "Data tidak Ditemukan\n";
                            }
                            goto lanjut;
                }
                else
                {
                	cout << "\nMasukkan inputan Valid";
                    goto ulang;
                }
               
        default :
            goto awal;
            break;
    }

    lanjut :
    	char yt;
    	cout << "Apakah ingin mencari Data mahasiswa lain (Y / N): "; cin >> yt;
    	if(yt == 'y' || yt == 'Y')
    	{
    		system("cls");	
    		goto opsi;
		}
		else
		{
			system("cls");
			cout << "\nTerima Kasih Telah Menggunakan Program Ini\n";
        garis();
        cout << "\nSalam Dari Muhid Mustari - Universitas Muslim Indonesia - Fakultas Ilmu Komputer\n";
        garis();
		}
        
    return 0;
}

void tabel (struct mahasiswa data[100], int jumlah)	// Fungsi untuk menampilkan tabel output
{
    list();
    for(int x=0; x<jumlah; x++)
    {
        output(data, x);
    }
    garis();
}

void urut (struct mahasiswa data[100], struct mahasiswa temp, int x, int y)	/* Fungsi selection sort dikarenakan program ini saya menggunakan 2 mode
    ascending dan descending jadi terlalu ribet kalau saya mengetik ulang pengurutannya*/
{
   	 	temp.nim = data[x].nim;		// Proses Urut NIM
    	data[x].nim = data[y].nim;
        data[y].nim = temp.nim;

                        temp.uts = data[x].uts;		// Proses Urut UTS
                        data[x].uts = data[y].uts;
                        data[y].uts = temp.uts;

        temp.uas = data[x].uas;		// Proses Urut UAS
    	data[x].uas = data[y].uas;
        data[y].uas = temp.uas;

                        temp.kuis = data[x].kuis;		// Proses Urut Kuis
                        data[x].kuis = data[y].kuis;
                        data[y].kuis = temp.kuis;

        temp.proyek = data[x].proyek;		// Proses Urut Proyek
        data[x].proyek = data[y].proyek;
        data[y].proyek = temp.proyek;

                        temp.kehadiran = data[x].kehadiran;		// Proses Urut Kehadiran
                        data[x].kehadiran = data[y].kehadiran;
                        data[y].kehadiran = temp.kehadiran;

        temp.hasil = data[x].hasil;		// Proses Urut Nilai Akhir
        data[x].hasil = data[y].hasil;
        data[y].hasil = temp.hasil;

                        temp.grade = data[x].grade;		// Proses Urut Grade
                        data[x].grade = data[y].grade;
                        data[y].grade = temp.grade;

}

void output (struct mahasiswa data[100], int x)	// Fungsi yang menyimpan data output lalu menampilkan
{
        cout << x+1 <<"\t"<< data[x].nim << "\t" << data[x].uts << "\t"
        << data[x].uas << "\t" << data[x].kuis << "\t" << data[x].proyek
        << "\t" << data[x].kehadiran << "\t\t" << data[x].hasil << "\t"
        << data[x].grade << "\n";
}
