void rearranging_cards()
{
    bool unique = true;
    do
    {
        unique = true;

        for (int i = 0; i < 3; i++)
            new_place[i] = rand() % (3) + 1;

        if (new_place[0] == new_place[1] || new_place[1] == new_place[2] || new_place[0] == new_place[2])
            unique = false;

    } while (!unique);
}