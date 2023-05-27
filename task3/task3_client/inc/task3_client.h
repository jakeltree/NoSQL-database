

#pragma once

#include <string>
#include <vector>
#include <nlohmann/json.hpp>
#include "../../ext/cpp-httplib/httplib.h"

using namespace std;
using json = nlohmann::json;

/*! @file 
 *  Здесь мы декларируем класс JsonMethods
 */
const char baseUrl[] = "http://localhost:8080";
 
/*! @class JsonMethods
 *  Класс для отправки сообщений на сервер Literature и прекращения его работы 
 */

class JsonMethods {
 public:
    /*! @brief Отправить сообщение. 
     *
     *  Функция получает строку и массив строк, на их основе получает
     *  JSON-структуру Send и отправляет на сервер при помощи запроса POST.
     *  @param[in] Command Строка с командой, посылаемой на сервер. 
     *  @param[in] Param Дополнительные параметры к команде.
     *  @param[out] success_status Успешность выполнения операции.
     */
    int Send(string, vector<string> = {});

   
    /*! @brief Прекратить работу сервера. 
     *  Посылает специальную команду на сервер при помощи запроса GET, в ответ
     *  на которой сервер обязан ответить.
     *  @param[in] file_name Название файла, из которого читаем JSON-структуру.
     *  @param[out] success_status Успешность выполнения операции.
     */
    void Shutdown();
};
