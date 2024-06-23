#include "System.h"
#include "Song.h"
#include "User.h"

void registerUser(){
    User user;
    int i = 0;
    char username[21];
    char email[31];
    char phoneNumber[16];
    char password[21];
    char option=NULL;
    int nameVerify=0;
    int passVerify=0;
    int mailVerify=0;
    int phoneVerify=0;


    printf(". . . Sistema de registro BEPEFY . . .\n");

    user.id = searchIdFree();


    while(nameVerify == 0 && option!=27)
    {
        system("cls");
        printf("Ingresar nombre de usuario:\n");
        printf("Maximo 20 caracteres.\n");    //verificar medidad del usuario.
        fflush(stdin);
        gets(username);
        if(!searchUsername(username))
        {
            strcpy(&user.username, username);
            nameVerify=1;
        }
        else
        {
            system("cls");
            printf("El nombre de usuario no esta disponible \n");
            printf("Desea cancelar la carga? Presione ESCAPE.\n");
            printf("Para volver a intentarlo presione cualquier tecla.\n");
            fflush(stdin);
            option = getch();
        }
    }

    while(passVerify == 0 && option!=27)
    {
        system("cls");
        printf("Ingresar contrasenia:\n");
        printf("Longitud de 8 a 15 caracteres.\n");
        fflush(stdin);
        gets(password);
        if(strlen(password)<=15 && strlen(password)>=8)
        {
            strcpy(&user.passWord, password);
            passVerify = 1;
        }
        else
        {
            printf("Error. La contrasenia ingresada no posee la longitud expresada.\n");
            printf("Desea cancelar la carga? Presione ESCAPE.\n");
            printf("Para volver a intentarlo presione cualquier tecla.\n");
            fflush(stdin);
            option = getch();
        }
    }

    while(mailVerify == 0 && option!=27)
    {
        system("cls");
        printf("Ingresar correo electronico:\n");
        printf("Maximo 30 caracteres.\n");
        fflush(stdin);
        scanf("%s",&email);
        if(verifyValidEmail(email) == 0){

                printf("El email ya esta en uso, intente uno diferente\n");
                printf("Desea cancelar la carga? Presione ESCAPE.\n");
                printf("Para volver a intentarlo presione cualquier tecla.\n");
                fflush(stdin);
                option = getch();
            }else{
                strcpy(&user.email, email);
                mailVerify=1;
            }

    }

    while(phoneVerify == 0 && option!=27)
    {
        system("cls");
        printf("Ingresar numero de telefono:\n");
        fflush(stdin);
        gets(phoneNumber);
        phoneVerify = verifyPhone(phoneNumber);
        if(phoneVerify == 1)
        {
            printf("Numero de telefono ocupado, por favor eliga otro\n");
            printf("Desea cancelar la carga? Presione ESCAPE.\n");
            printf("Para volver a intentarlo presione cualquier tecla.\n");
            fflush(stdin);
            option = getch();
        }
        else
        {
            strcpy(&user.phoneNumber, phoneNumber);
            phoneVerify = 1;
        }
    }
    if(phoneVerify == 1)
    {
        saveUser(user);
    }
    system("cls");
}

void loginMenuBepefy(){

    int option = 0;
    int verify = 1;

    do{

        printf("\nSELECCIONE UNA OPCION.\n");

        printf("\n1. Registrarse\n");
        printf("\n2. Login\n");
        printf("\n3. Salir\n\n");

        fflush(stdin);
        option = getch();
        system("cls");

        switch(option){

            case 49:
                registerUser();
                break;

            case 50:
                subMenuLogin();
                break;

            case 51:

                break;

            default:

                printf("Opcion incorrecta.\n");
                system("pause");
                system("cls");
                break;

        }

    }while(option != 51);

    printf("\nFIN DEL PROGRAMA\n");
}

void subMenuLogin(){
    char infoToLogin [20];
    char password [15];
    User*user = NULL;

        printf("\Login\n");

        printf("Ingrese su nombre de usuario,email o numero de telefono: ");
        fflush(stdin);
        gets(infoToLogin);

        printf("Ingrese su contraseña: ");
        fflush(stdin);
        gets(password);

        user = accVerify(user,infoToLogin,password);
        if(user){
           menuBepefy(user);
        }else{
            system("cls");
            printf("Usuario o contraseña Incorrecto\n");
            printf("Por favor intente nuevamente con un usuario o contraseña valido\n");
            system("pause");
            system("cls");
        }
}

void menuBepefy(User*user){

    int option = NULL;

    system("mode con: cols=81 lines=23");
    system("color F0");


//    gotoxy(2,6);
    printf("            ____     _____    ____    _____    _____   __     __                \n");
//    gotoxy(2,7);
    printf("           | __ )   | ____|  |  _ \\  | ____|  |  ___|  \\ \\   / /              \n");
//    gotoxy(2,8);
    printf("           |  _ \\   |  _|    | |_) | |  _|    | |_      \\ \\_/ /               \n");
//    gotoxy(2,9);
    printf("           | |_) |  | |___   |  __/  | |___   |  _|      \\   /                   \n");
//    gotoxy(2,10);
    printf("           |____/   |_____|  |_|     |_____|  |_|         |_|                    \n");




   do {


    printf ("\n\n\n\n\n\n");
    printf("                 _____________________________________________\n");
    printf("                |       ELIGE UNA OPCION PARA CONTINUAR       |\n");
    printf("                |_____________________________________________|\n");
    printf("                | 1. Usuario                                  |\n");
    printf("                | 2. Biblioteca                               |\n");
    printf("                | 3. Salir                                    |\n");
    printf("                |_____________________________________________|\n");

        fflush(stdin);
        option = getch();
        system("cls");



         switch (option)
         {
             case 49:
                menuUser(user);
                break;

            case 50:
<<<<<<< HEAD
                //menuSongs(user);
                break;

            case 51:
                menuLibrary();
                break;

            case 52:
=======
                menuSongs(user);
>>>>>>> 135fb54a4c06537985fcf26d0c12ce7056f0814c
                break;

            default:
                printf("Opcion incorrecta.\n");
                system("cls");
                break;
         }
    }while (option != 52);

    printf("FIN DE PROGRAMA");

  }

void menuUser(User*user){

    int flag = 0;
    int option = 0;

    do{

        printf("\nELIGA UNA OPCION.\n");

        printf("\n1. Dar de baja al usuario.\n");
        printf("\n2. Editar usuario.\n");
        printf("\n3. Mostrar datos del usuario.\n");
        printf("\n4. Volver al menu principal.\n\n");

        fflush(stdin);
        option = getch();
        system("cls");

        switch(option){

            case 49:

                ///flag = delUser(stUser);
                break;

            case 50:

                subEditMenuUser(user);
                break;

            case 51:

                showUser(posUser(user));
                break;

            default:

                printf("Opcion incorrecta.\n");
                system("cls");
                break;

        }
    }while(option != 52);
}
<<<<<<< HEAD

void menuSongs(User user){
=======
void menuSongs(User*user){
>>>>>>> 135fb54a4c06537985fcf26d0c12ce7056f0814c

    int option = 0;

    do{

        printf("\nELIGA UNA OPCION.\n");

        printf("\n1. Mi Playlist\n");
        printf("\n2. Biblioteca\n");
        printf("\n3. Buscar una cancion\n");
        printf("\n4. Volver al menu principal.\n\n");

        fflush(stdin);
        option = getch();
        system("cls");

        switch(option){

            case 49:

                ///menuPlaylist();
                break;

            case 50:

                ///menuLibrary();
                break;

            case 51:

                ///stSong searchSong();
                break;


            default:

                printf("Opcion incorrecta.\n");
                system("cls");
                break;

        }
    }while(option !=52);
}

void menuLibrary(){

    int option = NULL;

    do{

        printf("\nELIJA UNA OPCION.\n\n");

        printf("\n1. Ver la Biblioteca completa.\n");
        printf("\n2. ver Biblioteca por Orden alfabetico.\n");
        printf("\n3. ver Biblioteca por Genero.\n");
        printf("\n4. Salir.\n\n");

        fflush(stdin);
        option = getch();
        system("cls");

        switch(option){

            case 49:

//                void showLibrary(stSong[]);
                break;

            case 50:

//                void showLibraryAtoZ(stSong[]);
                break;

            case 51:

//                void showLibraryGenre(stSong[]);
                break;

            default:

                printf("Opcion incorrecta.\n");
                system("cls");
                break;

        }

    }while(option != 52);
}






