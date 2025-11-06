print("\nBienvenue au Calculaeur (Calculateur santé/sans T)")
start_over_quizz = True

while start_over_quizz:
    quizz_finished = False
    day_counter = 0
    unbalanced_meal_warning = False
    total_minutes_of_physical_activity = 0
    empty_stomach_physical_activity_warning = False
    average_physical_activity_per_day = 0
    advice_flag = False

    while not quizz_finished:
        day_counter += 1
        print("\nJour " + str(day_counter))

        valid_input = False
        breakfast_answer = ""
        while not valid_input:
            breakfast_answer_input = str(input("\nAvez-vous déjeuné ce matin? (o/N) "))
            if breakfast_answer_input == "O" or breakfast_answer_input == "o":
                breakfast_answer = True
                valid_input = True
            elif breakfast_answer_input == "N" or breakfast_answer_input == "n":
                breakfast_answer = False
                valid_input = True
            else:
                print("Veuillez entrer une réponse valide o/n ou O/N")

        meal_balance_answer = \
            float(input("Quelle fraction de votre alimentation a consisté de fruits et légumes? (0.xx) "))
        if meal_balance_answer < 0.20:
            unbalanced_meal_warning = True
        elif meal_balance_answer > 0.80:
            unbalanced_meal_warning = True

        daily_physical_activity_in_minutes_answer = \
            float(input("Combien de minutes d'activité physique avez-vous effectué? "))
        total_minutes_of_physical_activity += daily_physical_activity_in_minutes_answer
        if daily_physical_activity_in_minutes_answer >= 30 and breakfast_answer is False:
            empty_stomach_physical_activity_warning = True

        valid_input = False
        while not valid_input:
            add_day = str(input("Voulez-vous ajouter un jour? (o/N) "))
            if add_day == "O" or add_day == "o":
                quizz_finished = False
                valid_input = True
            elif add_day == "N" or add_day == "n":
                quizz_finished = True
                valid_input = True
            else:
                print("Veuillez entrer une réponse valide o/n ou O/N")

    average_physical_activity_per_day = total_minutes_of_physical_activity / day_counter

    print("\nCalcul des conseils en cours... ")

    if unbalanced_meal_warning:
        print("\nVous ne mangez pas équilibré tous les jours! Visez 50% de fruits et légumes.")
        advice_flag = True
    if average_physical_activity_per_day < 30:
        print("\nVous ne faites pas suffisamment de sport! Visez 30 minutes par jour en moyenne.")
        advice_flag = True
    if empty_stomach_physical_activity_warning:
        print("\nAttention! Vous ne devez pas faire du sport sur un estomac vide!")
        advice_flag = True

    if advice_flag is False:
        print("\nVous mangez et bougez très bien! Continuez sur cette belle lancée.")

    print("\nFin du calcul! ")

    restart_quizz_answer = str(input("\nSouhaitez-vous recommencer le questionnaire? (o/N) "))
    if restart_quizz_answer == "O" or restart_quizz_answer == "o":
        start_over_quizz = True
    else:
        start_over_quizz = False

print("\nPassez une belle journée!")
