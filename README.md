# task3

JSON база данных на сервере под Unix системой и консольный клиент для доступа к нему посредством кастомных HTTP запросов.
Зависимости: [Httplib](https://github.com/yhirose/cpp-httplib), [Nlohmann JSON](https://github.com/nlohmann/json).

## Документация Doxygen
[Папка с документацией](https://github.com/jakeltree/task3/tree/master/task3/html)

Открыть index.html.

## Запуск проекта 
### Собрать проект
```
cd task3_build
cmake ../task3
```

### Запустить проект
Сервер 
```
cd task3_server
./main_server
```
Клиент
```
cd task3_client
./main_client
```
