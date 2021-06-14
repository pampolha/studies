using System;
using System.Collections.Generic;
using System.Threading;
using System.Linq;

namespace Locadora
{
    public class Prateleira
    {
        private List <Jogo> jogos = new List<Jogo>();
        
        public void AdicionarJogo(Jogo j)
        {
            jogos.Add(j); 
        } 
        public string ProcurarNome(string nome)
        {
            string jogosEncontrados;
            jogosEncontrados = "\tJogos encontrados: \n\n"; 
            jogosEncontrados += String.Join("\n", jogos.Where(J => J.ToString().Trim().ToLower().Contains(nome.ToLower().Trim() ) ) );
            return jogosEncontrados;  
        }

        public void AlugarJogo(string nome)
        {
            //Jogo jogoAlugado = ProcurarNome(nome);
            
            //jogos.Remove(jogoAlugado);
        }
        public void MostrarJogos()
        {
            foreach (Jogo jogo in jogos)
            {
                Console.WriteLine(jogo.Nome + "");
            }
        }
    }
}
