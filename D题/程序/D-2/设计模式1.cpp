class Role{
};
class Box
{
	public:
		void BeOpen(Role u);
};
class Role
{
	private:
		int Money;
		int HP;
	public:
		void OpenBox(Box u)
		{
			u.BeOpen(this);
		}
		void AddMoney(int i)
		{
			Money=Money+i;
		}
		void ReduceHP(int i)
		{
			HP=HP-i;
		}
};
class Solider:public Role
{
	public:
		Solider()
		{
			Money=0;
			HP=100;
		}
		void Change()
		{
			HP=HP*0.9;
			Money=Money*1.2;
		}
};
class Mage:public Role
{
	public:
		Mage()
		{
			Money=0;
			HP=100;
		}
		void Change()
		{
			HP=0.7*HP;
			Money=1.4*Money;
		}
};
class moneyBox:public Box
{
	private:
		int Money;
	public:
		moneyBox(int i)
		{
			Money=i;
		}
		void BeOpen(Role r)
		{
			r.AddMoney(Money);
			Money=0;
		}
};
class poisonBox:public Box
{
	public:
		void BeOpen(Role r)
		{
			r.Change();
		}
};
