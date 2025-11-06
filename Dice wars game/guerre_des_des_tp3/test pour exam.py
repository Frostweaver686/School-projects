# liste = []
#
# liste.extend(["chien", "chat", "patate"])
#
# print(liste)
# test = "recursif"

# test_2 = test[0].upper()
# print(test_2)
# print(test[1:])
def upper_rec(chaine):


    if chaine == "":
        return chaine
    print(chaine)
    return chaine[0].upper() + upper_rec(chaine[1:])

upper_rec("recursif")


