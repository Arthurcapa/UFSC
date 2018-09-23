#ifndef _COZINHA_H_
#define _COZINHA_H_

#include "pedido.h"
#include "tarefas.h"


/**/
extern void cozinha_init(int cozinheiros, int bocas, int frigideiras, int garcons, int tam_balcao);
extern void cozinha_destroy();
extern void* processar_pedido(void* p);
void preparar_sopa();
void preparar_carne();
void preparar_spaghetti();

void cozinha_init(int cozinheiros, int bocas, int frigideiras, int garcons, int tam_balcao){
  //Cria os buffers

}

void* processar_pedido(void* p){
  /**/
  pedido_t* pp = (pedido_t*)p;
  const char* name = pedido_prato_to_name(pp->prato);
  if (strcmp(name,"SOPA") == 0){
    preparar_sopa(p);
  }
  if (strcmp(name, "CARNE") == 0){
    preparar_carne(p);

  }
  if (strcmp(name, "SPAGHETTI") == 0){
    preparar_spaghetti(p);
  }
  return NULL;
}

void cozinha_destroy(){
  //Free buffers, delete threads and destroy semaphores

}

void preparar_carne(pedido_t p){
  /**/
  carne_t* carne = create_carne();

  //sem_wait(&cozinheiros);                 //espera por um cozinheiro livre

  cortar_carne(carne);    //coloca cozinheiro como ocupado (DE)

  temperar_carne(carne);  //coloca cozinheiro como ocupado (DE)

  //sem_wait(&fogoes);
  //sem_wait(&frigideiras);
  grelhar_carne(carne);         //coloca cozinheiro como ocupado (DE)
  //sem_post(&frigideiras);     //NESSE MOMENTO, TOMAR CUIDADO COM DEADLOCK
  //sem_post(&fogoes);


  prato_t* prato = create_prato(p);
  empratar_carne(carne, prato);      //coloca cozinheiro como ocupado (DE)
  notificar_prato_no_balcao(prato);

  //sem_post(&cozinheiros);


  //inserir prato no buffer do balcao

  //sem_wait(&garcons);
  entregar_pedido(prato);
  //sem_post(&garcons);


  destroy_carne(carne);
  //destroy_prato(prato);


}

void preparar_spaghetti(pedido_t p){
  /**/
  molho_t* molho = create_molho();
  agua_t* agua = create_agua();
  spaghetti_t* spaghetti = create_spaghetti();
  bacon_t* bacon = create_bacon();

  //sem_wait(&cozinheiros);

  //sem_wait(&bocas);
  esquentar_molho(molho);  //cozinheiro esperando
  //sem_post(&bocas);

  //sem_wait(&bocas);
  ferver_agua(agua);      //cozinheiro esperando
  //sem_post(&bocas);

  //sem_wait(&bocas);
  cozinhar_spaghetti(spaghetti, agua);      //cozinheiro esperando
  //sem_post(&bocas);

  //sem_wait(&bocas);
  dourar_bacon(bacon);              //
  //sem_post(&bocas);


  prato_t* prato = create_prato(p);
  empratar_spaghetti(spaghetti, molho, bacon, prato);   //cozinheiro ocupado

  notificar_prato_no_balcao(prato);
  //inserir prato no buffer do balcao

  //sem_post(&cozinheiros);

  //espera um garcom ficar livre
  entregar_pedido(prato);

  destroy_agua(agua);
  //destroy_prato(prato);
  destroy_molho(molho);
  destroy_bacon(bacon);
  destroy_spaghetti(spaghetti);
}

void preparar_sopa(pedido_t p){
  /**/
  agua_t* agua = create_agua();
  legumes_t* legumes = create_legumes();

  //sem_wait(&cozinheiros);

  //sem_wait(&bocas);
  ferver_agua(agua);   //cozinheiro esperando
  //sem_post(&bocas);

  cortar_legumes(legumes);  //cozinheiro ocupado

  //sem_wait(&bocas);
  caldo_t* caldo = preparar_caldo(agua);  //cozinheiro esperando
  //sem_post(&bocas);

  //sem_wait(&bocas);
  cozinhar_legumes(legumes, caldo);    //cozinheiro esperando
  //sem_post(&bocas);

  prato_t* prato = create_prato(p);
  notificar_prato_no_balcao(prato);
  //inserir prato no buffer do balcao

  //sem_post(&cozinheiros);


  //sem_wait(&garcons);
  entregar_pedido(prato);
  //sem_post(&garcons);

  //destroy_agua(agua);
  //destroy_prato(prato);
  destroy_legumes(legumes);
  destroy_caldo(caldo);
}



#endif /* _COZINHA_H_ */
