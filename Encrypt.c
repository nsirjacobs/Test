


void encrypt(uint8_t*keys,uint32_t size_key,uint32_t index,char* server_message,uint8_t* files,uint32_t size) {
  // arriver a file => index, genre
  files += sizeof(uint8_t)*index; // normalement on est a la bonne dimension?

  int nmatrices = size/size_key;

  char* copy_server_message;


  for (size_t i = 0; i < nmatrices; i++) {
    for (size_t j = 0; j < nmatrices; j++) {  //savoir quelle *sousmatrice* on multiplie

      for (size_t k = 0; k < size_key; k++) {  //savoir quelle case de la sousmatrice on calcule...
        for (size_t l = 0; l < size_key; l++) { //c'estlong
          copy_server_message = server_message;
          copy_server_message += sizeof(uint8_t)*((size_key*i)+(size*j)+(size_key*k)+(size*l)) //on bouge le pointeur vers la case que l'on veut remplir.
          uint8_t sol = 0;
          for (size_t m = 0; m < size_key; m++) {  //le calcul en lui même
            uint8_t a =  *(uint8_t *) key+ ((k*size_key)+m)*sizeof(uint8_t);
            uint8_t b =  *(uint8_t *) files+ ((l*size)+m)*sizeof(uint8_t);     //pas sur d'avoir récupéré correctement les valeurs
            sol += a*b;
            }
          *(uint8_t*) copy_server_message = sol;
        }
      }
    }
  }
}


//[1234]
//[1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16]
//nmatrices = 4
//
