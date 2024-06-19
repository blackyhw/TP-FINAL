#include "System.h"
#include "Song.h"
#include "User.h"

void registerUser()
{
    User user;
    char username[21];
    char email[31];
    char phoneNumber[16];
    char password[21];
    char option=NULL;
    int i=0;
    int nameVerify=0;
    int passVerify=0;
    int mailVerify=0;
    int phoneVerify=0;


    printf(". . . Sistema de registro BEPEFY . . .\n");

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
            printf("Email invalido.\n");
            printf("Desea cancelar la carga? Presione ESCAPE.\n");
            printf("Para volver a intentarlo presione cualquier tecla.\n");
            fflush(stdin);
            option = getch();
            }else if(verifyMail(email) == 0){
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
        if(phoneVerify == 0)
        {
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

        printf("\nELIGA UNA OPCION.\n");

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
    User *a = NULL;
    int val = NULL;

        printf("\Login\n");

        printf("Ingrese su nombre de usuario,email o numero de telefono: ");
        fflush(stdin);
        gets(infoToLogin);

        printf("Ingrese su contraseña: ");
        fflush(stdin);
        gets(password);

        val = accVerify(a,infoToLogin,password);
        if(val == 1 ){
           menuBepefy();
        }else{
            system("cls");
            printf("Usuario o contraseña Incorrecto\n");
            printf("Por favor intente nuevamente con un usuario o contraseña valido\n");
            system("pause");
            system("cls");
        }
}

void menuBepefy(){


    int option=NULL;

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
    printf("                | 2. Canciones                                |\n");
    printf("                | 3. Biblioteca                               |\n");
    printf("                | 4. Salir                                    |\n");
    printf("                |_____________________________________________|\n");

        fflush(stdin);
        option = getch();
        system("cls");



         switch (option)
         {
             case 49:
                menuUser();
                break;

            case 50:
                menuSongs();
                break;

            case 51:
                //void menuLibrary();
                break;

            case 52:
                break;

            default:
                printf("Opcion incorrecta.\n");
                Beep(750, 800);
                system("cls");
                break;
         }
    }while (option != 52);

    printf("FIN DE PROGRAMA");
    Beep(750, 800);

  }

void menuUser(){
    int flag = 0;
    int option = 0;

    while(1){

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

                ///menuEditUser();
                break;

            case 51:

                ///showUser(stUser);
                break;

            case 52:

                menuBepefy();
                break;

            default:

                printf("Opcion incorrecta.\n");
                system("cls");
                break;

        }
    }
}

void menuSongs(){

    int option = 0;

    while(1){

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

            case 52:

                menuBepefy();
                break;

            default:

                printf("Opcion incorrecta.\n");
                system("cls");
                break;

        }
    }
}







