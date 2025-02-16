#include <bits/stdc++.h>

using namespace std;

// Estrutura para representar uma tarefa
struct Task {
    int id, deadline, profit;
};

// Função auxiliar de comparação para ordenar as tarefas por lucro decrescente
bool compare(Task a, Task b) {
    return a.profit > b.profit;
}

pair<int, int> jobScheduling(vector<Task> &tasks) {
    sort(tasks.begin(), tasks.end(), compare);

    int maxDeadline = 0;
    for(Task task : tasks) {
        maxDeadline = max(maxDeadline, task.deadline);
    }

    // Array para marcar slots ocupados (inicialmente todos vazios)
    vector<int> schedule(maxDeadline + 1, -1);
    int totalProfit = 0, countJobs = 0;

    for(Task task : tasks) {
        // encontramos o último slot disponível antes do deadline
        for (int t = task.deadline; t > 0; t--) {
            if(schedule[t] == -1){ // verifica se o slot está disponível
                schedule[t] = task.id;
                totalProfit += task.profit;
                countJobs++;
                break;
            }
        }
    }

    return {countJobs, totalProfit};

}

int main() {
    // Lista de tarefas {id, prazo, lucro}
    vector<Task> tasks = {
        {1, 2, 100}, 
        {2, 1, 50}, 
        {3, 2, 10}, 
        {4, 1, 20}, 
        {5, 3, 30}
    };

    pair<int, int> result = jobScheduling(tasks);

    cout << "Número máximo de tarefas realizadas: " << result.first << endl;
    cout << "Lucro total obtido: " << result.second << endl;

    return 0;
}