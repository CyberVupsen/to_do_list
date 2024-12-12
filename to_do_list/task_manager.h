#ifndef TASK_MANAGER
#define TASK_MANAGER

#include <vector>
#include <string>
#include "chrono.h"
#include <fstream>


namespace TaskManager_ns
{
    struct Task{
        Task(std::string task_name, std::string task_text, Chrono_ns::Period period);
        
        std::string name {"My note"};
        std::string text;
        Chrono_ns::Period period;
        unsigned long long get_id() { return id; }
        void set_id(unsigned long long i_d){ id = i_d; }

        private:
            unsigned long long id;
    };

    std::ostream& operator << (std::ostream& os, const Task& t);
    bool operator == (const Task& t1, const Task& t2);
    bool operator != (const Task& t1, const Task& t2);


    class TaskManager{

    public:
        TaskManager();

        void add_task(Task task);
        void delete_task(Task task);
        void update_task(Task old_task, Task new_task);

        std::vector<Task> get_tasks() const;
        std::vector<Task> get_tasks(Chrono_ns::Date date) const;
        
    private:
        std::vector<Task> tasks;
        std::ifstream in;
        std::ofstream out;
        void download_tasks();
    };

    void download_counter();
}


#endif //TASK_MANAGER